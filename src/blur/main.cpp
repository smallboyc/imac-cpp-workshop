#include <iostream>
#include <sil/sil.hpp>
#include <vector>

void getBlur(sil::Image &image, sil::Image &newImage)
{
    // identity : 0,0,0,0,1,0,0,0,0
    // sharpen : 0,-1,0,-1,5,-1,0,-1,0
    // emboss : 0,-1,-2,1,1,-1,2,1,0
    // outline : -1, -1, -1, -1, 8, -1, -1, -1, -1
    // blur : 1,2,1,2,4,2,1,2,1
    std::vector<float> kernel{-1, -1, -1, -1, 8, -1, -1, -1, -1};
    bool divide{false};
    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {

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
                        total += kernel[number];
                    }
                    number++;
                }
            }
            if (divide)
                result /= total;

            newImage.pixel(x, y) = result;
        }
    }
}

int main()
{
    sil::Image image{"images/tloupartI.jpg"};
    sil::Image newImage{image.width(), image.height()};
    getBlur(image, newImage);
    newImage.save("output/pouet.png");
}