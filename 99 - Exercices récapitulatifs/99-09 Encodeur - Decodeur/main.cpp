#include <cstdlib>
#include <iostream>
#include <string>
#include <cctype>
#include <fstream>

#include "encodeFile.cpp"
#include "decodeFile.cpp"

int main() {
    encodeFile("src/source.txt",  "src/chiffre.txt", 3);
    decodeFile("src/chiffre.txt", "src/claire.txt",  3);

    system("cat src/chiffre.txt");  // afficher le contenu
    system("cat src/claire.txt");   // .. des fichiers créés

    return EXIT_SUCCESS;
}