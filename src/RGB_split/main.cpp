#include <sil/sil.hpp>

int main()
{
    sil::Image image{"images/logo.png"};
    sil::Image voidImage{image.width(), image.height()};
    for (int x{30}; x < image.width() - 30; x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            voidImage.pixel(x, y).r = image.pixel(x + 30, y).r;
            voidImage.pixel(x, y).g = image.pixel(x, y).g;
            voidImage.pixel(x, y).b = image.pixel(x - 30, y).b;
        }
    }

    for (int x{0}; x < 30; x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            voidImage.pixel(x, y).r = image.pixel(x + 30, y).r;
            voidImage.pixel(x, y).g = image.pixel(x, y).g;
            voidImage.pixel(x, y).b = image.pixel(x, y).b;
        }
    }
    for (int x{image.width() - 30}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            voidImage.pixel(x, y).r = image.pixel(x, y).r;
            voidImage.pixel(x, y).g = image.pixel(x, y).g;
            voidImage.pixel(x, y).b = image.pixel(x - 30, y).b;
        }
    }

    voidImage.save("output/pouet.png");
}