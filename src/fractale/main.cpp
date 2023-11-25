#include <sil/sil.hpp>
#include <complex>

int main()
{
    sil::Image image{500, 500};
    for (float x{0}; x < image.width(); x++)
    {
        for (float y{0}; y < image.height(); y++)
        {
            float newX{x / 125 - 2};
            float newY{y / 125 - 2};
            int count{0};
            std::complex<float> c{newX, newY};
            std::complex<float> z{0.f, 0.f};
            float result{0.f};
            while (count < 50)
            {
                result = static_cast<float>(count) / 50;
                z = z * z + c;

                if (std::abs(z) > 2)
                    break;

                image.pixel(x, y) = glm::vec3{result};
                count++;
            }
        }
    }

    image.save("output/pouet.png");
}