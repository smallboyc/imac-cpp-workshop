#include <sil/sil.hpp>

int main()
{
    sil::Image image{"images/photo_faible_contraste.jpg"};
    float number{1.5f};

    for (glm::vec3 &color : image.pixels())
    {
        color.r = pow(color.r, number);
        color.g = pow(color.g, number);
        color.b = pow(color.b, number);
    }

    image.save("output/pouet.png");
}