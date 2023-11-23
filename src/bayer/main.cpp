#include <sil/sil.hpp>
#include <vector>

void bwImage(sil::Image &image)
{
    for (glm::vec3 &color : image.pixels())
    {
        float moyenne{(color.r + color.g + color.b) / 3.0f};
        color.r = moyenne;
        color.g = moyenne;
        color.b = moyenne;
    }
}

int main()
{
    sil::Image image{"images/photo_faible_contraste.jpg"};
    int bayer_n{4};
    std::vector<std::vector<double>> bayer_matrix_4x4{
        {-0.5, 0, -0.375, 0.125},
        {0.25, -0.25, 0.375, -0.125},
        {-0.3125, 0.1875, -0.4375, 0.0625},
        {0.4375, -0.0625, 0.3125, -0.1875},
    };
    bwImage(image);

    for (int i{0}; i < image.height(); i++)
    {
        for (int j = 0; j < image.width(); j++)
        {
            float orig_color = image.pixel(i, j).r;
            glm::vec3 color_result{0, 0, 0};
            float bayer_value = bayer_matrix_4x4[i % bayer_n][j % bayer_n];
            float output_color = orig_color + bayer_value;
            if (output_color > 0.5f)
            {
                color_result = {1, 1, 1};
            }
            image.pixel(i, j) = color_result;
        }
    }

    image.save("output/pouet.png");
}