#include <iostream>

using namespace std;

int main() {
    int i, j, k;

    i = 0; k = i++;
    cout << "A : i = " << i << " k = " << k << endl;
    //A : i = 1 k = 0

    i = 1; k = ++i;
    cout << "B : i = " << i << " k = " << k << endl;
    //B : i = 2 k = 2

    i = 2; j = 3;
    k = i++ * ++j;
    cout << "C : i = " << i << " j = " << j << " k = " << k << endl;
    //C : i = 3 j = 4 k = 8

    i = 3; j = 4;
    k = i *= --j;
    cout << "D : i = " << i << " j = " << j << " k = " << k << endl;
    //D : i = 9 j = 3 k = 9
}
