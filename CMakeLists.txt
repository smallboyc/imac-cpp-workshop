cmake_minimum_required(VERSION 3.20)

# You can set the name of your project here
project(ImageEditor)
# Download the sil library
include(FetchContent)
FetchContent_Declare(
    sil
    GIT_REPOSITORY https://github.com/JulesFouchy/Simple-Image-Lib
    GIT_TAG 89bd175cd55fb6daa9e99b218e869c3d516043f4
)
FetchContent_MakeAvailable(sil)
function(add_exercise FOLDER)
    add_executable(${FOLDER})

    # Choose your C++ version
    target_compile_features(${FOLDER} PRIVATE cxx_std_17)

    # Prevents compiler-specific extensions to C++ because they might allow code to compile on your machine but not on other people's machine
    set_target_properties(${FOLDER} PROPERTIES
        CXX_EXTENSIONS OFF)

    # Add all the source files
    file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/${FOLDER}/* lib/*)
    target_sources(${FOLDER} PRIVATE ${SOURCES})
    target_include_directories(${FOLDER} PRIVATE src/${FOLDER} lib)


    # Link sil into the project
    target_link_libraries(${FOLDER} PRIVATE sil)

endfunction(add_exercise)


add_exercise(black_white)
add_exercise(cercle)
add_exercise(disque)
add_exercise(fractale)
add_exercise(glitch)
add_exercise(gradient)
add_exercise(green)
add_exercise(luminosite)
add_exercise(mirror)
add_exercise(mosaique)
add_exercise(mosaique_miroir)
add_exercise(negative)
add_exercise(noise)
add_exercise(normalisation)
add_exercise(RGB_split)
add_exercise(rosace)
add_exercise(blur)
add_exercise(vortex)
add_exercise(bayer)
add_exercise(pixel_sorting)
add_exercise(rotate_90)
add_exercise(switch_color)