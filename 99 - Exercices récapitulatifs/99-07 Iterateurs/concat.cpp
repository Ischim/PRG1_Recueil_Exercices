//
// Created by ischi on 30.01.2025.
//


template<typename Iterator1, typename Iterator2>
Iterator2 concat(Iterator1 first, Iterator1 last, Iterator2 result) {
    for(auto it = first; it != last; ++it) {
        result = copy(it->first, it->second, result);
    }

    return result;
}
