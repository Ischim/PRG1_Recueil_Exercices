#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

// Definition des alias
using Pixel_value = unsigned short;
using Image = vector<vector<Pixel_value>>;

struct Pt {
    int x;
    int y;
};
using Kernel = vector<Pt>;

// Prototype
Image make_image(size_t width, size_t height, Pixel_value color = numeric_limits<Pixel_value>::lowest());
Image dilate(const Image& img, const Kernel& kern, Pixel_value color = numeric_limits<Pixel_value>::lowest());

int main() {
    Pixel_value black = 0;
    Image image = make_image(1920,1080,black);

    for(size_t i = 0; i < 20; ++i)
        image[200 + i][300 - i] = 65535; // dessine une ligne oblique blanche

    Kernel kernel { Pt{0,0}, Pt{-1,0}, Pt{1,0}, Pt{0,1}, Pt{0,-1}};
    Image dilated = dilate(image, kernel, black);
}

Image make_image(size_t width, size_t height, Pixel_value color) {
    return {height, vector<Pixel_value>(width, color)};
}

Image dilate(const Image& img, const Kernel& kern, Pixel_value color) {
    Image result(img);

    for(size_t y = 0; y < img.size(); ++y) {
        for(size_t x = 0; x < img[y].size(); ++x) {
            result[y][x] = numeric_limits<Pixel_value>::lowest();
            bool pas_de_voisin = true;
            for(const Pt& k : kern) {
                size_t nx = x + k.x;
                size_t ny = y + k.y;
                if(nx < img[y].size() and ny < img.size()) {
                    result[y][x] = max(result[y][x],result[ny][nx]);
                    pas_de_voisin = false;
                }
            }
            if (pas_de_voisin) result[y][x] = color;
        }
    }
    return result;
}
