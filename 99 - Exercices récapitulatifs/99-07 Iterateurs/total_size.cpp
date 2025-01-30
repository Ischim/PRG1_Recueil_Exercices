//
// Created by ischi on 30.01.2025.
//
#include <cstddef>

template<typename Iterator>
size_t total_size(Iterator first, Iterator last) {
    size_t taille {};
    for(auto it = first; it != last; ++it) {
        taille += distance(it->first, it->second);
    }

    return taille;
}