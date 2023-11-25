#include <iostream>
#include <sil/sil.hpp>
#include <vector>

sil::Image getBlur(sil::Image const image, sil::Image newImage)
{
    std::vector<float> kernel{1, 2, 1, 2, 4, 2, 1, 2, 1};
    bool divide{true};
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
    return newImage;
}

int main()
{
    sil::Image image{"images/photo.jpg"};
    sil::Image newImage{image.width(), image.height()};
    sil::Image copy{image};
    sil::Image result{image.width(), image.height()};

    image = getBlur(image, newImage);
    for (int i{0}; i < 7; i++)
    {
        copy = {getBlur(copy, newImage)};
    }

    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            result.pixel(x, y) = image.pixel(x, y) - copy.pixel(x, y);
        }
    }

    result.save("output/pouet.png");
}