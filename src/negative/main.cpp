#include <sil/sil.hpp>

int main()
{
    sil::Image image{"images/logo.png"};
    //x = 1 - x
    for (glm::vec3 &color : image.pixels())
    {
        color.r = 1 - color.r;
        color.g = 1 - color.g;
        color.b = 1 - color.b;
    }
    image.save("output/pouet.png");
}