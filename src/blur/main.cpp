#include <iostream>
#include <sil/sil.hpp>

void getBlur(sil::Image &image)
{
    glm::vec3 result{0};
    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            int count{0};
            for (int i{-1}; i <= 1; i++)
            {
                for (int j{-1}; j <= 1; j++)
                {
                    if (x + i >= 0 && x + i < image.width() && y + j >= 0 && y + j < image.height())
                    {
                        result += image.pixel(x + i, y + j);
                        count++;
                    }
                }
            }
            result /= count;

            image.pixel(x, y) = result;
        }
    }
}

int main()
{
    sil::Image image{"images/tlou.jpg"};
    getBlur(image);
    image.save("output/pouet.png");
}