#include <iostream>
#include <iomanip>
#include <vector>
#include <limits>

using namespace std;

template <typename T>
using bin_t = T;

template<typename T>
ostream& operator<<(ostream& os, const bin_t<T>& val) {
    os << "0b";

    if(val == 0) {
        os << "0";
        return os;
    }

    bin_t<T> temp = val;

    vector<bool> bin;
    while (temp != 0)
    {
        bin.push_back(temp % 2);
        temp /= 2;
    }
    for(auto it = bin.rbegin(); it != bin.rend(); ++it) os << *it;
    return os;
}

int main() {
    /*int a, b;
    bool error;

    do {
        error = !(cin >> hex >> a) or a < 0;
        if (error) {
            cout << "Erreur de saisie, veuilliez ressaisir a : " << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }while (error);

    do
    {
        error = !(cin >> b) or b < 0;
        if (error)
        {
            cout << "Erreur de saisie, veuilliez ressaisire b : " << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (error);
    
    cout << a + b << endl;*/

    bin_t<int> bin = 0b01001;
    cout << bin;
    return 0;
}