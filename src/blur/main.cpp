#include <iostream>
#include <sil/sil.hpp>
#include <vector>

void getBlur(sil::Image &image, sil::Image &newImage)
{

    std::vector<float> kernel{1};
    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            // int count{0};
            glm::vec3 result{0};
            int number{0};
            float total{0.f};
            for (int i{-1}; i <= 1; i++)
            {
                for (int j{-1}; j <= 1; j++)
                {
                    if (x + i >= 0 && x + i < image.width() && y + j >= 0 && y + j < image.height())
                    {
                        result += image.pixel(x + i, y + j) * kernel[number];
                        number++;
                        total += kernel[number];
                    }
                }
            }
            result /= total;

            newImage.pixel(x, y) = result;
        }
    }
}

int main()
{
    sil::Image image{"images/tlou.jpg"};
    sil::Image newImage{image.width(), image.height()};
    getBlur(image, newImage);
    newImage.save("output/pouet.png");
}