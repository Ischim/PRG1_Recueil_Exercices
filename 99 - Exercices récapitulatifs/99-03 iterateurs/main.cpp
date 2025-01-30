#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <functional>

using namespace std;

template<typename Iterator, typename Comp>
pair<Iterator, Iterator> plus_long_sequence_croissante(Iterator first, Iterator last, Comp comp) {
    if (first == last) return {first,last};

    pair<Iterator,Iterator> output (first, next(first));
    Iterator new_first = first;
    while (++first != last) {
        if(comp(*first, *prev(first))) new_first = first;

        if(distance(new_first,first) + 1 > distance(output.first, output.second)) {
            output.first = new_first;
            output.second = next(first);
        }
    }
    return output;
}

template<typename Iterator>
pair<Iterator, Iterator> plus_long_sequence_croissante(Iterator first, Iterator last) {
    return plus_long_sequence_croissante(first, last, less<typename Iterator::value_type>{});
}

int main() {
    vector<int> v{6, 3, 4, 5, 4, 3, 1, 2, 2, 3, 4, 3, 7};

    cout << "Plus long sequence croissante (1): ";
    auto r1 = plus_long_sequence_croissante(v.begin(), v.end());
    for (auto it = r1.first; it != r1.second; ++it)
        cout << *it << ' ';

    cout << "\nPlus long sequence croissante (2): ";
    auto r2 = plus_long_sequence_croissante(v.cbegin(), v.cend(), less<int>{});
    for (auto it = r2.first; it != r2.second; ++it)
        cout << *it << ' ';

    cout << "\nPlus long sequence décroissante : ";
    auto r3 = plus_long_sequence_croissante(v.begin(), v.end(), greater<int>{});
    for (auto it = r3.first; it != r3.second; ++it)
        cout << *it << ' ';

    cout << endl;
}