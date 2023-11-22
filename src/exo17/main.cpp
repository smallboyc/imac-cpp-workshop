#include <sil/sil.hpp>
#include <complex>

int main()
{
    sil::Image image{500, 500};
    std::complex<float> c{3.f, 2.f}; // Définis le nombre c = 3 + 2*i
    std::complex<float> z{0.f, 0.f};
    while (true)
    {
        if (std::abs(z) > 2)
        {
            image.pixel(z.real(), z.imag()) = {0, 0, 0};
            break;
        }
        else
        {
            if (z.real() < image.width() && z.imag() < image.height())
            {
                z = z * z + c;
                image.pixel(z.real(), z.imag()) = {1, 1, 1};
            }

            // }
        }

        image.save("output/pouet.png");
    }
}