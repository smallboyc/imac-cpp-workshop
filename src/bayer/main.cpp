#include <sil/sil.hpp>
#include <vector>

int main()
{
    sil::Image image{500, 500};
    int bayer_n{4};
    std::vector<std::vector<int>> bayer_matrix_4x4{
        {-0.5, 0, -0.375, 0.125},
        {0.25, -0.25, 0.375, -0.125},
        {-0.3125, 0.1875, -0.4375, 0.0625},
        {0.4375, -0.0625, 0.3125, -0.1875},
    };

    for (int i = 0; i < image.height(); i++)
    {
        float orig_color = get_screen_gradient(i);
        for (int j = 0; j < image.width(); j++)
        {
            glm::vec3 color_result{0, 0, 0};
            float bayer_value = bayer_matrix_4x4[i % bayer_n][j % bayer_n];
            float output_color = orig_color + (bayer_r * bayer_value);
            // Color screen blue to white
            if (output_color < (NUM_VALUES / 2))
            {
                color_result = {1, 1, 1};
            }
            *PIXEL_PTR((&screen), j, i, 1) = color_result;
        }
    }

    image.save("output/pouet.png");
}