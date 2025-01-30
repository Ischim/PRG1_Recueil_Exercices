#include "display_csv.h"
#include <iostream>

using namespace std;

int main() {
    try {
        display_csv("data.txt", ',', 10);
    } catch (File_not_found& e) {
        cerr << "File not found \n";
        exit(-1);
    }
}