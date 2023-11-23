#include <sil/sil.hpp>
#include <iostream>

int main()
{
    sil::Image image{"images/logo.png"};
    sil::Image sortedImage{image.width(), image.height()};
    std::vector<glm::vec3> v{};
    for (int x{0}; x < sortedImage.width(); x++)
    {
        for (int y{0}; y < sortedImage.height(); y++)
        {
            
        }
    }
    if (image.pixel(10, 3).r > image.pixel(10, 200).r)
        std::cout << "yes";
    sortedImage.save("output/pouet.png");
}