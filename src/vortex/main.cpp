#include <sil/sil.hpp>
#include <glm/gtx/matrix_transform_2d.hpp>
#include <cmath>

glm::vec2 rotated(glm::vec2 point, glm::vec2 center_of_rotation, float angle)
{
    return glm::vec2{glm::rotate(glm::mat3{1.f}, angle) * glm::vec3{point - center_of_rotation, 0.f}} + center_of_rotation;
}

int main()
{
    sil::Image image{"images/melanchon.jpg"};
    sil::Image voidImage{image.width(), image.height()};

    glm::vec2 positionCenter{image.width() / 2, image.height() / 2};
    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            glm::vec2 point{x, y};
            double rayon{sqrt(pow(x - positionCenter.x, 2) + pow(y - positionCenter.y, 2))};
            glm::vec2 newPoint{rotated(point, positionCenter, rayon * 0.01f)};
            if (newPoint.x < image.width() && newPoint.x >= 0 && newPoint.y < image.height() && newPoint.y >= 0)
                voidImage.pixel(x, y) = image.pixel(newPoint.x, newPoint.y);
        }
    }
    voidImage.save("output/pouet.png");
}
