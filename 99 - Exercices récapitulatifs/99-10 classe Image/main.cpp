#include <iostream>
#include <cassert>

#include "Image.h"

using namespace std;

int main() {

    Color cyan{0, 255, 255};
    cout << "cyan codé comme (" << +cyan.R << "," << +cyan.G << "," << +cyan.B << ")" << endl;

    Coord p{10, 20};
    cout << "p(" << p.x << "," << p.y << ")" << endl;
    cout << "origin(" << Coord::origin.x << "," << Coord::origin.y << ")" << endl;

    Color black{0,0,0};
    Image imageHD(1280, 720, black);
    cout << "Image HD de taille " << imageHD.getw() << "x" << imageHD.geth() << endl;
    cout << "La composante G du pixel de coordonnée p est " << +imageHD[p].G << endl;

    imageHD[p] = cyan;
    cout << "La composante G du pixel de coordonnée p est " << +imageHD[p].G << endl;

    Image sub = imageHD.subImage(p,20,10);
    cout << "sub de taille " << sub.getw() << "x" << sub.geth() << endl;

    cout << "La composante B du pixel en (0,0) est " << +sub[Coord::origin].B << endl;
}