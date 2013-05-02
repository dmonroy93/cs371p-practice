/*
CS371p: Quiz #15 (5 pts)
*/

/* -----------------------------------------------------------------------
1. What is the output of the following program?
   (4 pts)

A(int)
A(A) A(A)
A(A)
A(A) A(A) ~A()
~A() ~A() ~A() ~A() ~A()
*/

#include <iostream>  // cout, endl
#include <vector>    // vector

using namespace std;

struct A {
    A             ()         {cout << "A() ";}                  // default constructor
    A             (int)      {cout << "A(int) ";}               // int constructor
    A             (const A&) {cout << "A(A) ";}                 // copy constructor
    ~A            ()         {cout << "~A() ";}                 // destructor
    A& operator = (const A&) {cout << "=(A) "; return *this;}}; // copy assignment operator

int main () {
    {
    A v(3);
    cout << endl;

    vector<A> x(2, v);
    cout << endl;

    vector<A> y(1, v);
    cout << endl;

    y = x;
    cout << endl;
    }
    cout << endl;

    return 0;}
