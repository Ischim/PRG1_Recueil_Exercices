//
// Created by ischi on 30.01.2025.
//

#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <vector>
#include <cstdint>

struct Color {
    uint8_t R, G, B;
};

struct Coord {
    size_t x, y;
    static const Coord origin;
};

class Image {
public:
    Image(size_t width, size_t height, const Color& c): h(height), w(width), data(w * h, c) {}

    size_t getw() const {return this->w;}
    size_t geth() const {return this->h;}

    Color const& operator[] (const Coord& p) const { return data[idx(p)];}
    Color& operator[] (const Coord& p) { return data[idx(p)];}

    Image subImage(Coord p1, size_t dw, size_t dh) const;
private:
    size_t h;
    size_t w;
    std::vector<Color> data;
    size_t idx (const Coord& p) const {
        if(p.x >= w or p.y >= h) throw std::out_of_range("Image");
        return p.x + w * p.y;
    }
};

const Coord Coord::origin{};

Image Image::subImage(Coord p1, size_t dw, size_t dh) const {
    // validate input
    idx(p1);
    idx(Coord{p1.x + dw - 1, p1.y + dh - 1});

    Image out {dw, dh, Color{}};
    for(Coord p{0,0}, pi{p1}; p.y < dh; ++p.y, ++pi.y) {
        for(p.x = 0, pi.x = p1.x; p.x < dw; ++p.x, ++pi.x) {
            out[p] = (*this)[pi];
        }
    }
    return out;
}

#endif //IMAGE_HPP
