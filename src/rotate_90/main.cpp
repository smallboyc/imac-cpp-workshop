#include <sil/sil.hpp>

int main()
{
    sil::Image image{"images/logo.png"};
    sil::Image voidImage{image.height(), image.width()};
    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
            voidImage.pixel(voidImage.width() - 1 - y, x) = image.pixel(x, y);
    }
    voidImage.save("output/pouet.png");
}