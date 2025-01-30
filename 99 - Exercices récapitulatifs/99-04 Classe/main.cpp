#include <iostream>
#include <array>
#include <vector>
#include <cassert>  // assert

using namespace std;

class MonException { };

class Vec3 {
public:
    Vec3() : vect({}) {}
    Vec3(double a, double b, double c): vect({a,b,c}){}

    template<typename Iterator>
    Vec3(Iterator first, Iterator last);

    Vec3 operator+=(const Vec3& other);

    static Vec3 axis(size_t pos);

    double& operator[](size_t pos) {return vect[pos];}
    double operator[](size_t pos) const {return vect[pos];}
private:
    array<double, 3> vect;
};

template<typename Iterator>
Vec3::Vec3(Iterator first, Iterator last){
    if (distance(first,last) != 3) throw MonException{};
    copy(first,last,vect.begin());
}

Vec3 Vec3::axis(size_t pos) {
    assert(pos < 3);
    Vec3 v{};
    v[pos] = 1;
    return v;
}


Vec3 Vec3::operator+=(const Vec3& other) {
    for(size_t i = 0; i < 3; ++i) {
        this->vect[i] += other[i];
    }
    return *this;
}

Vec3 operator+(Vec3 lhs, Vec3 const& rhs) {
    return lhs += rhs;
}

ostream& operator<< (ostream& os, const Vec3& v) {
    os << "(" << v[0] << "," << v[1] << "," << v[2] << ")";
    return os;
}

int main() {
    Vec3 v1{};
    cout << "v1 = " << v1 << endl;

    v1[2] = 2;
    cout << "v1 = " << v1 << endl;

    array a{1., 3., 2.};
    const Vec3 v2(a.begin(),a.end());
    cout << "v2 = " << v2 << endl;

    for (size_t i = 0; i < 3; ++i)
        cout << "v2[" << i << "] = " << v2[i] << ((i < 2) ? ", " : "\n");

    vector b{4., 2., 5.};
    Vec3 v3(b.begin(), b.end());
    cout << "v3 = " << v3 << endl;

    Vec3 v4 = v2 + v3;
    cout << "v4 = " << v4 << endl;

    v4 += v2;
    cout << "v4 = " << v4 << endl;

    Vec3 x = Vec3::axis(0);
    cout << "x = " << x << endl;
    Vec3 y = Vec3::axis(1);
    cout << "y = " << y << endl;
    Vec3 z = Vec3::axis(2);
    cout << "z = " << z << endl;
}
