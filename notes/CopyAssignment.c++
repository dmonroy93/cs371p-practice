// ------------------
// CopyAssignment.c++
// ------------------

#include <algorithm> // copy, equal, fill, swap
#include <cassert>   // assert
#include <cstddef>   // size_t
#include <iostream>  // cout, endl
#include <iterator>  // distance

template <typename T>
class my_vector {
    private:
        std::size_t _s;
        T*          _a;

    public:
        explicit my_vector (std::size_t s, const T& v = T()) :
        //If we're not given what to fill my_vector with then we initialize with default values
                _s (s),
                _a (new T[_s]) {
            std::fill(begin(), end(), v);}

        my_vector (const my_vector& that) :
                _s (that._s),
                _a (new T[_s]) {
            std::copy(that.begin(), that.end(), begin());}

        my_vector& operator = (my_vector that) {
            //return by reference because you want to be able to use it then
            std::swap(_s, that._s); //here if you did _s = that._s there would be no prob bc it's an int so no leaks
            std::swap(_a, that._a); //you have to swap because if you did _a = that._a you'd get a memory leak
            return *this;
            //since you invoke it in this (which is a pointer) you need to dereference
        }

        ~my_vector () {
            delete [] _a;}
            //use delete[] because it's an array

        T* begin () {
            return _a;}

        const T* begin () const {
            return _a;}

        T* end () {
            return _a + _s;}

        const T* end () const {
            return _a + _s;}

        std::size_t size () const {
            return _s;}};

int main () {
    using namespace std;
    cout << "CopyAssignment.c++" << endl;

    {
    const my_vector<int> x(10, 2);
    const my_vector<int> y = x;
    assert(equal(x.begin(), x.end(), y.begin()) == true);
    }

    {
          my_vector<int> x(10, 2);
    const my_vector<int> y(20, 3);
    x = y;
    assert(equal(x.begin(), x.end(), y.begin()) == true);
    }

    cout << "Done." << endl;
    return 0;}
