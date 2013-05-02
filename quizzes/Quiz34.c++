/*
CS371p: Quiz #34 (5 pts)
*/

/* -----------------------------------------------------------------------
1. What is the output of the following program?
   (4 pts)

B::f(double)
A::f(int)
*/

#include <iostream> // cout, endl

using namespace std;

struct A {
    virtual void f (int) {
        cout << "A::f(int)" << endl;}};

struct B : A {
    void f (double) {
        cout << "B::f(double)" << endl;}};

int main () {
    B x;
    x.f(2);

    A& r = x;
    r.f(2);

    return 0;}
