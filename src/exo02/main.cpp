#include <sil/sil.hpp>

int main()
{
    sil::Image image{"images/logo.png"};
    for (glm::vec3 &color : image.pixels())
    {
        std::swap(color.b, color.r);
    }
    image.save("output/pouet.png");
}