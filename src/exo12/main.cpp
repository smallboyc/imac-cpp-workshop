#include <sil/sil.hpp>

int main()
{
    sil::Image image{500, 500};
    int rayon{60};
    int thickness{2};
    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            if (pow(x - image.width() / 2, 2) + pow(y - image.height() / 2, 2) >= pow(rayon, 2) && pow(x - image.width() / 2, 2) + pow(y - image.height() / 2, 2) <= pow(rayon + thickness, 2))
            {
                image.pixel(x, y) = {1,
                                     1,
                                     1};
            }
        }
    }
    image.save("output/pouet.png");
}