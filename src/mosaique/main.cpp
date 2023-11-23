#include <iostream>
#include <sil/sil.hpp>

void newImacPoster(sil::Image &image, sil::Image &newImage, int const &position_x, int const &position_y)
{

    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            newImage.pixel(position_x + x, position_y + y) = image.pixel(x, y);
        }
    }
}

int main()
{
    sil::Image image{"images/arcane.jpg"};
    int ratio{5};
    sil::Image newImage{ratio * image.width(), ratio * image.height()};

    for (int i{0}; i < ratio; i++)
    {
        for (int j{0}; j < ratio; j++)
            newImacPoster(image, newImage, j * image.width(), i * image.height());
    }
    newImage.save("output/pouet.png");
}