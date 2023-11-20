#include <sil/sil.hpp>

int main()
{
    sil::Image image{300, 200};
    // x = 1 - x
    for (float x{0}; x < image.width(); x++)
    {
        for (float y{0}; y < image.height(); y++)
        {
            image.pixel(x, y).r = x / image.width() - 1;
            image.pixel(x, y).g = x / image.width() - 1;
            image.pixel(x, y).b = x / image.width() - 1;
        }
    }
    image.save("output/pouet.png");
}