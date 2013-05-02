// ---------
// Cache.c++
// ---------

#include <cassert>  // assert
#include <cstring>  // strcat, strcmp
#include <iostream> // cout, endl

int main () {
    using namespace std;
    cout << "Cache.c++" << endl;

    {
    const char* a = "abc";
    const char* b = "abc";
    assert(a == b);
    }

    {
    const char a[] = "abc";
    const char b[] = "abc";
    assert(a != b);
    assert(strcmp(a, b) == 0);
    }

    {
    char a[4] = "a";
    strcat(a, "bc");
    const char* b = "abc";
    assert(a != b);
    assert(strcmp(a, b) == 0);
    }

    cout << "Done." << endl;
    return 0;}
