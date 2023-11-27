#include <iostream>
#include <sil/sil.hpp>
#include <array>
#include <vector>
#include <cmath>
#include <algorithm>

glm::vec3 moyenneSecteur(sil::Image &image, std::array<std::array<int, 2>, 2> &secteur, int &x, int &y)
{
    int increase_i{1};
    int increase_j{1};
    // J'ajoute ou je retire ?
    if (secteur[0][1] < 0)
        increase_i = -1;
    if (secteur[1][1] < 0)
        increase_j = -1;

    // On détermine la moyenne du secteur
    glm::vec3 moyenne_secteur{0.f};
    int count{0};
    for (int i{secteur[0][0]}; i != secteur[0][1] + increase_i; i += increase_i)
    {
        for (int j{secteur[1][0]}; j != secteur[1][1] + increase_j; j += increase_j)
        {
            if (x + i >= 0 && x + i < image.width() && y + j >= 0 && y + j < image.height())
            {
                moyenne_secteur += image.pixel(x + i, y + j);
                count++;
            }
        }
    }
    moyenne_secteur /= (float)(count);

    return moyenne_secteur;
}

glm::vec3 varianceSecteur(sil::Image &image, std::array<std::array<int, 2>, 2> &secteur, int &x, int &y, glm::vec3 moyenne_secteur)
{
    int increase_i{1};
    int increase_j{1};
    // J'ajoute ou je retire ?
    if (secteur[0][1] < 0)
        increase_i = -1;
    if (secteur[1][1] < 0)
        increase_j = -1;
    // On détermine la variance du secteur
    glm::vec3 variance{0.f};
    int count{0};
    for (int i{secteur[0][0]}; i != secteur[0][1] + increase_i; i += increase_i)
    {
        for (int j{secteur[1][0]}; j != secteur[1][1] + increase_j; j += increase_j)
        {
            if (x + i >= 0 && x + i < image.width() && y + j >= 0 && y + j < image.height())
            {
                variance += (image.pixel(x + i, y + j) - moyenne_secteur) * (image.pixel(x + i, y + j) - moyenne_secteur);
                count++;
            }
        }
    }
    variance /= (float)(count);

    variance = sqrt(variance);

    return variance;
}

int main()
{
    sil::Image image{"images/photo.jpg"};
    sil::Image voidImage{image.width(), image.height()};

    std::array<std::array<int, 2>, 2> secteur_1{std::array{0, 2}, std::array{0, 2}}; // {x,y}
    std::array<std::array<int, 2>, 2> secteur_2{std::array{0, 2}, std::array{0, -2}};
    std::array<std::array<int, 2>, 2> secteur_3{std::array{0, -2}, std::array{0, -2}};
    std::array<std::array<int, 2>, 2> secteur_4{std::array{0, -2}, std::array{0, 2}};

    // Parcours de tous les pixels
    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            std::vector<std::array<glm::vec3, 2>> varianceTable;

            std::array<glm::vec3, 2> calcul_secteur1{moyenneSecteur(image, secteur_1, x, y), varianceSecteur(image, secteur_1, x, y, moyenneSecteur(image, secteur_1, x, y))};
            varianceTable.push_back(calcul_secteur1);
            std::array<glm::vec3, 2> calcul_secteur2{moyenneSecteur(image, secteur_2, x, y), varianceSecteur(image, secteur_2, x, y, moyenneSecteur(image, secteur_2, x, y))};
            varianceTable.push_back(calcul_secteur2);
            std::array<glm::vec3, 2> calcul_secteur3{moyenneSecteur(image, secteur_3, x, y), varianceSecteur(image, secteur_3, x, y, moyenneSecteur(image, secteur_3, x, y))};
            varianceTable.push_back(calcul_secteur3);
            std::array<glm::vec3, 2> calcul_secteur4{moyenneSecteur(image, secteur_4, x, y), varianceSecteur(image, secteur_4, x, y, moyenneSecteur(image, secteur_4, x, y))};
            varianceTable.push_back(calcul_secteur4);

            // On veut la variance la plus faible, ici à l'indice 0
            std::sort(
                varianceTable.begin(),
                varianceTable.end(),
                [](std::array<glm::vec3, 2> const &array1, std::array<glm::vec3, 2> const &array2)
                {
                    return glm::length(array1[1]) < glm::length(array2[1]);
                });

            voidImage.pixel(x, y) = varianceTable[0][0];
        }
    }

    voidImage.save("output/pouet.png");
}
