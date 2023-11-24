#include <sil/sil.hpp>

int main()
{
    sil::Image image{"images/anakin.jpg"};
    for (int x{0}; x < image.width() / 2; x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            std::swap(image.pixel(x, y), image.pixel(image.width() - (x + 1), y));
        }
    }
    image.save("output/pouet.png");
}