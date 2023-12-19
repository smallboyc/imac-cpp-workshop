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
            // `pow(x - image.width() / 2, 2) + pow(y - image.height() / 2, 2)` est utilisé deux fois, vous pouvez le stocker dans une variable:
            // ça évite des calculs en double, et ça rend le code plus lisible
            float const distance_squared{pow(x - image.width() / 2, 2) + pow(y - image.height() / 2, 2)};
            if (distance_squared >= pow(rayon, 2) && distance_squared <= pow(rayon + thickness, 2))
            {
                image.pixel(x, y) = {1,
                                     1,
                                     1};
            }
        }
    }
    image.save("output/pouet.png");
}