#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <string>
#include <cassert>

using namespace std;

int transformer(string & s, string from, string_view to  ) {
    assert(from.size() == to.size());

    //On met from en majuscule
    transform(from.cbegin(), from.cend(), from.begin(), ::toupper);

    int nb_change{};
    // On parcout s par charactère
    for(char& c : s) {
        // on veut savoir si c est dans from, si oui, à quelle place
        size_t p = from.find(toupper(c));

        if (p != string::npos) {
            ++nb_change;
            c = isupper(c) ? toupper(to[p]) : tolower(to[p]);
        }
    }

    return nb_change;
}

int main() {
    string s = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Phasellus facilisis at dolor eget congue. Duis in lacus placerat ante consectetur tempor. Aliquam lorem nunc, laoreet quis feugiat accumsan, vulputate vitae justo.";
    cout << transformer(s,"abcdefgh.!,:","fghabcde!,:.") << endl;
    cout << s << endl;
    cout << transformer(s,"fghabcde!,:.","abcdefgh.!,:") << endl;
    cout << s << endl;

    return EXIT_SUCCESS;
}
