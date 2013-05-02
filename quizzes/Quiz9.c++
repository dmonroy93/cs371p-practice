/*
CS371p: Quiz #9 (5 pts)
*/

/* -----------------------------------------------------------------------
1. In C++, what four methods constitute the orthodox canonical class form?
   [Sec. 5.6.1, Pg. 115]
   (2 pts)

default constructor
copy constructor
copy assignment operator
destructor
*/

/* -----------------------------------------------------------------------
2. What is the output of the following program?
   (2 pts)

3 4 false
4 4 true
*/

#include <iostream> // cout, endl

int main () {
    using namespace std;
    cout << boolalpha;   // 'bool' outputs as 'true' or 'false'

    {
    int i = 2;
    int j = ++i;
    j++;
    cout << i          << " ";
    cout << j          << " ";
    cout << (&i == &j) << endl;
    }

    {
    int  i = 2;
    int& j = ++i;
    j++;
    cout << i          << " ";
    cout << j          << " ";
    cout << (&i == &j) << endl;
    }

    return 0;}
