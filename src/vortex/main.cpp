#include <glm/gtx/matrix_transform_2d.hpp>
#include <sil/sil.hpp>

glm::vec2 rotated(glm::vec2 v, float angle)
{
    return glm::vec2{glm::rotate(glm::mat3{1.f}, angle) * glm::vec3{v, 1.f}};
}

int main()
{
    sil::Image image{"images/logo.png"};
    int x{0};
    int y{0};
    glm::vec2 position{x + image.width(), y + image.height()};
    position = rotated(position, 12);
    image.save("output/pouet.png");
}
