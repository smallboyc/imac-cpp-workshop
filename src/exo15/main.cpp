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

void mirrorPoster(sil::Image &image, bool const &reverse)
{
    int divide_x{2};
    int divide_y{1};
    if (reverse)
    {
        divide_x = 1;
        divide_y = 2;
    }

    for (int x{0}; x < image.width() / divide_x; x++)
    {
        for (int y{0}; y < image.height() / divide_y; y++)
        {
            int select_x{image.width() - (x + 1)};
            int select_y{y};
            if (reverse)
            {
                select_x = x;
                select_y = image.height() - (y + 1);
            }

            std::swap(image.pixel(x, y), image.pixel(select_x, select_y));
        }
    }
}

int main()
{
    sil::Image const image{"images/melanchon.jpg"};
    int ratio{7};
    bool reverse{false};
    sil::Image newImage{ratio * image.width(), ratio * image.height()};

    for (int i{0}; i < ratio; i++)
    {
        for (int j{0}; j < ratio; j++)
        {
            sil::Image copy{image};
            if (j % 2 != 0)
            {
                mirrorPoster(copy, false);
            }
            if (i % 2 != 0)
            {
                mirrorPoster(copy, true);
            }
            newImacPoster(copy, newImage, j * image.width(), i * image.height());
        }
    }
    newImage.save("output/pouet.png");
}