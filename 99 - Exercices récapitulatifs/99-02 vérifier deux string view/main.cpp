#include <iostream>
//#include <string>
#include <string_view>
#include <algorithm>

using namespace std;

string ensemble_trie(string_view s) {
    // créer string
    auto a = string(s);

    // mettre en majuscule
    transform(a.cbegin(),a.cend(),a.begin(),::toupper);

    // trier ordre alphanumérique
    sort(a.begin(),a.end());

    // supprimer les doublons
    a.erase(unique(a.begin(),a.end()), a.end());

    return a;
}

bool verifier(string_view a,  string_view b) {
    // avoir des strings trier
    auto ea = ensemble_trie(a);
    auto eb = ensemble_trie(b);

    // voir si les tailles sont identiques, et que ea et eb soient egaux
    return ea.size() == a.size() && eb.size() == b.size() && ea == eb;

}

void tester(string_view a, string_view b) {
   cout << '\"' << a << "\" "
        << (verifier(a, b) ? "" : "in") << "compatible avec "
        << '\"' << b << '\"' << endl;
}

int main() {
    // ok
    tester("abcdef","FEDBAC");

    // Pas même charactère
    tester("abcdef","xyz123");

    // Doublon
    tester("abcA","cAba");
}
