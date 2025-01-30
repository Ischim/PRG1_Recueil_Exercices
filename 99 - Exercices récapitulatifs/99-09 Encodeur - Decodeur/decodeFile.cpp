//
// Created by ischi on 30.01.2025.
//
#ifndef DECODE_FILE_CPP
#define DECODE_FILE_CPP
#include <string>
#include "encodeFile.cpp"

void decodeFile(const std::string& input, const std::string& output, int shift) {
    encodeFile(input,output, - shift);
}

#endif //DECODE_FILE_CPP