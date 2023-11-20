#include <sil/sil.hpp>
#include <cmath>

void createCircle(sil::Image &image, int &x, int &y, int &center_x, int &center_y, int &rayon, int &thickness)
{
    if (pow(x - center_x, 2) + pow(y - center_y, 2) >= pow(rayon - thickness, 2) && pow(x - center_x, 2) + pow(y - center_y, 2) <= pow(rayon + thickness, 2))
    {
        image.pixel(x, y) = {1,
                             1,
                             1};
    }
}

int main()
{
    sil::Image image{500, 500};
    int rayon{60};
    int thickness{2};
    int center_x{image.width() / 2};
    int center_y{image.height() / 2};
    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            createCircle(image, x, y, center_x, center_y, rayon, thickness);
            for (int i{1}; i <= 6; i++)
            {
                int newCenter_x{static_cast<int>(center_x + rayon * static_cast<float>(cos(i * 3.14f / 3)))};
                int newCenter_y{static_cast<int>(center_x + rayon * static_cast<float>(sin(i * 3.14f / 3)))};
                createCircle(image, x, y, newCenter_x, newCenter_y, rayon, thickness);
            }
        }
    }
    image.save("output/pouet.png");
}