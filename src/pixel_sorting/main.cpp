#include <sil/sil.hpp>
#include <iostream>
#include <vector>
#include <algorithm>
#include "random.hpp"

float brightness(glm::vec3 &color)
{
    return (color.r + color.g + color.b);
}

void getRectangle(sil::Image &image)
{
    std::vector<glm::vec3> table;
    glm::vec2 inputPositionStart{random_int(0, image.width()), random_int(0, image.height())};

    glm::vec2 rectangleSize{random_int(20, 30), 1};

    for (int i{0}; i < rectangleSize.x; i++)
    {
        for (int j{0}; j < rectangleSize.y; j++)
        {
            if (inputPositionStart.x + i < image.width() &&
                inputPositionStart.y + j < image.height())
                table.push_back(image.pixel(inputPositionStart.x + i, inputPositionStart.y + j));
        }
    }

    std::sort(table.begin(), table.end(), [](glm::vec3 &color1, glm::vec3 &color2)
              { return brightness(color1) < brightness(color2); });

    int count{0};
    for (int i{0}; i < rectangleSize.x; i++)
    {
        for (int j{0}; j < rectangleSize.y; j++)
        {
            if (inputPositionStart.x + i < image.width() &&
                inputPositionStart.y + j < image.height())
            {

                image.pixel(inputPositionStart.x + i, inputPositionStart.y + j) = table[count];
                count++;
            }
        }
    }
}

int main()
{
    sil::Image image{"images/logo.png"};
    sil::Image copy{image};
    for (int i{0}; i < 500; i++)
        getRectangle(copy);

    copy.save("output/pouet.png");
}