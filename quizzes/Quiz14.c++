/*
CS371p: Quiz #14 (5 pts)
*/

/* -----------------------------------------------------------------------
1. What is the output of the following program?
   (4 pts)

A()
A() A() A() A() A()
=(A) =(A) =(A) =(A) =(A)
~A() ~A() ~A() ~A() ~A()
~A()
*/

#include <algorithm> // fill
#include <iostream>  // cout, endl

using namespace std;

struct A {
    A             ()         {cout << "A() ";}                  // default constructor
    A             (int)      {cout << "A(int) ";}               // int constructor
    A             (const A&) {cout << "A(A) ";}                 // copy constructor
    ~A            ()         {cout << "~A() ";}                 // destructor
    A& operator = (const A&) {cout << "=(A) "; return *this;}}; // copy assignment operator

int main () {
    {
    A x;
    cout << endl;

    A* a = new A[5];
    cout << endl;

    fill(a, a + 5, x);
    cout << endl;

    delete [] a;
    cout << endl;
    }
    cout << endl;

    return 0;}
