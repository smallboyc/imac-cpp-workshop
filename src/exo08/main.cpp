#include <sil/sil.hpp>

int main()
{
    sil::Image image{"images/logo.png"};
    sil::Image voidImage{image.height(), image.width()};
    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            voidImage.pixel(voidImage.width() - 1 - y, x) = image.pixel(x, y);
        }
    }
    // for (int x{0}; x < voidImage.width() / 2; x++)
    // {
    //     for (int y{0}; y < voidImage.height(); y++)
    //     {
    //         std::swap(voidImage.pixel(x, y), voidImage.pixel(voidImage.width() - (x + 1), y));
    //     }
    // }
    voidImage.save("output/pouet.png");
}