#include <sil/sil.hpp>
#include "random.hpp"

int main()
{
    sil::Image image{"images/logo.png"};

    for (size_t i = 0; i < image.pixels().size(); i++)
    {
        int x_random = random_int(0, image.width());
        int y_random = random_int(0, image.height());
        image.pixel(x_random, y_random).r = random_float(0, 1.0f);
        image.pixel(x_random, y_random).g = random_float(0, 1.0f);
        image.pixel(x_random, y_random).b = random_float(0, 1.0f);
    }

    image.save("output/pouet.png");
}