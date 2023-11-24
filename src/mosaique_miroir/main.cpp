#include <iostream>
#include <sil/sil.hpp>

void printPoster(sil::Image const &image, sil::Image &newImage, int const &position_x, int const &position_y)
{
    for (int x{0}; x < image.width(); x++)
        for (int y{0}; y < image.height(); y++)
            newImage.pixel(position_x + x, position_y + y) = image.pixel(x, y);
}

void mirror(sil::Image &image, bool const reverse_y)
{
    int divide_x{2};
    int divide_y{1};

    if (reverse_y)
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
            if (reverse_y)
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
    sil::Image const image{"images/arcane.jpg"};
    int ratio{8};
    bool reverseEffect{true};
    sil::Image newImage{ratio * image.width(), ratio * image.height()};

    for (int i{0}; i < ratio; i++)
        for (int j{0}; j < ratio; j++)
        {
            sil::Image copy{image};

            if (reverseEffect)
            {
                if (j % 2 != 0)
                    mirror(copy, false);

                if (i % 2 != 0)
                    mirror(copy, true);
            }

            printPoster(copy, newImage, j * image.width(), i * image.height());
        }

    newImage.save("output/pouet.png");
}