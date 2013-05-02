/*
CS371p: Quiz #25 (5 pts)
*/

/* -----------------------------------------------------------------------
1. Name the two mechanisms through which interfaces can be separated.
   [The Interface Segregation Principle]
   (2 pts)

delegation
multiple inheritance
*/

/* -----------------------------------------------------------------------
2. Define operator != only in terms of ! and ==.
   Define the operators <=, >, and >= only in terms of ! and <.
   (2 pts)
*/

#include <cassert>  // assert
#include <iostream> // cout, endl

using namespace std;

class A {
    friend bool operator == (const A& lhs, const A& rhs) {
        return lhs._i == rhs._i;}

    friend bool operator < (const A& lhs, const A& rhs) {
        return lhs._i < rhs._i;}

    private:
        int _i;

    public:
        A (int i) {
            _i = i;}};

template <typename T>
bool operator != (const T& lhs, const T& rhs) {
    return !(lhs == rhs);}

template <typename T>
bool operator <= (const T& lhs, const T& rhs) {
    return !(rhs < lhs);}

template <typename T>
bool operator > (const T& lhs, const T& rhs) {
    return (rhs < lhs);}

template <typename T>
bool operator >= (const T& lhs, const T& rhs) {
    return !(lhs < rhs);}

int main () {
    A x = 2;
    A y = 3;

    assert(!(x == y));
    assert(x != y);

    assert(x <  y);
    assert(x <= y);
    assert(!(x >  y));
    assert(!(x >= y));

    cout << "Done." << endl;
    return 0;}
