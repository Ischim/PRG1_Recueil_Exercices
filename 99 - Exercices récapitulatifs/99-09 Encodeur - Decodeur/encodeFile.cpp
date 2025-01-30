//
// Created by ischi on 30.01.2025.
//
#ifndef ENCODE_FILE_CPP
#define ENCODE_FILE_CPP
#include <iostream>
#include <string>
#include <fstream>

void encodeFile(const std::string& input, const std::string& output, int shift) {
    std::ifstream file_in (input);

    if(!file_in) std::cerr << "Open file in : Error" << std::endl;

    std::ofstream file_out(output);

    if(!file_out) std::cerr << "Open file out : Error" << std::endl;

    shift %= 26;
    std::string line;

    while (getline(file_in,line)) {
        for(char& c : line) {
            if (std::isalpha(c)) {
                char base = isupper(c) ? 'A' : 'a';
                c = static_cast<char>(((c - base + shift) % 26) + base);
            }
        }
        file_out << line;
    }
    file_in.close();
    file_out.close();
}
#endif //ENCODE_FILE_CPP