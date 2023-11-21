#include <sil/sil.hpp>

int main()
{
    sil::Image image{"images/logo.png"};
    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height() / 2; y++)
        {
            std::swap(image.pixel(x, y), image.pixel(x, image.height() - (y + 1)));
        }
    }
    image.save("output/pouet.png");
}