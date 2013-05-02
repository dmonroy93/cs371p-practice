/*
CS371p: Quiz #37 (5 pts)
*/

/* -----------------------------------------------------------------------
1. What is the output of the following program?
   (4 pts)

B() A() C()
~C() ~A() ~B()
*/

#include <iostream> // cout, endl

using namespace std;

struct A {
    A  () {cout << "A() ";}
    ~A () {cout << "~A() ";}};

struct B {
    B  () {cout << "B() ";}
    ~B () {cout << "~B() ";}};

struct C : B, A {
    C  () {cout << "C() ";}
    ~C () {cout << "~C() ";}};

int main () {
    {
    C x;
    cout << endl;
    }
    cout << endl;

    return 0;}
