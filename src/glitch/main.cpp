#include <sil/sil.hpp>
#include "random.hpp"

void ExchangeRectangle(sil::Image &image)
{
    glm::vec2 inputPositionStart{random_int(0, image.width()), random_int(0, image.height())};
    glm::vec2 outputPositionStart{random_int(0, image.width()), random_int(0, image.height())};

    glm::vec2 rectangleSize{random_int(20, 30), random_int(3, 8)};

    for (int i{0}; i <= rectangleSize.x; i++)
    {
        for (int j{0}; j <= rectangleSize.y; j++)
        {
            if (inputPositionStart.x + i < image.width() &&
                inputPositionStart.y + j < image.height() &&
                outputPositionStart.x + i < image.width() &&
                outputPositionStart.y + j < image.height())
            {
                glm::vec3 temp(image.pixel(inputPositionStart.x + i, inputPositionStart.y + j));
                image.pixel(inputPositionStart.x + i, inputPositionStart.y + j) = image.pixel(outputPositionStart.x + i, outputPositionStart.y + j);
                image.pixel(outputPositionStart.x + i, outputPositionStart.y + j) = temp;
            }
        }
    }
}

int main()
{
    sil::Image image{"images/logo.png"};
    int range{100};
    for (int i{0}; i < range; i++)
    {
        ExchangeRectangle(image);
    }
    image.save("output/pouet.png");
}