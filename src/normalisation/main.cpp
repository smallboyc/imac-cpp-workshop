#include <sil/sil.hpp>

int main()
{
    sil::Image image{"images/photo_faible_contraste.jpg"};
    float darkPixel{1.0f};
    float whitePixel{0.0f};

    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {

            float moyenne{(image.pixel(x, y).r + image.pixel(x, y).g + image.pixel(x, y).b) / 3.0f};

            if (moyenne < darkPixel)
                darkPixel = moyenne;
            else if (moyenne > whitePixel)
                whitePixel = moyenne;
        }
    }

    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            image.pixel(x, y).r = (image.pixel(x, y).r - darkPixel) * 1 / whitePixel;
            image.pixel(x, y).g = (image.pixel(x, y).g - darkPixel) * 1 / whitePixel;
            image.pixel(x, y).b = (image.pixel(x, y).b - darkPixel) * 1 / whitePixel;
        }
    }

    image.save("output/pouet.png");
}