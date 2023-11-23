#include <sil/sil.hpp>
#include <complex>

int main()
{
    sil::Image image{500, 500};

    image.save("output/pouet.png");
}