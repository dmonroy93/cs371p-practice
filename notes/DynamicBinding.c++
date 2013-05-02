// ------------------
// DynamicBinding.c++
// ------------------

#include <cassert>  // assert
#include <iostream> // cout, endl, istream, ostream
#include <utility>  // !=

using namespace std::rel_ops;

class Shape {//these friends call on helper methods
    friend bool operator == (const Shape& lhs, const Shape& rhs) {
        return lhs.equals(rhs);}

    friend std::istream& operator >> (std::istream& lhs, Shape& rhs) {
        return rhs.read(lhs);}

    friend std::ostream& operator << (std::ostream& lhs, const Shape& rhs) {
        return rhs.write(lhs);}

    private:
        int _x;
        int _y;
//helper methods are protected and vitual
    protected:
        virtual bool equals (const Shape& that) const {
            return (_x == that._x) && (_y == that._y);}

        virtual std::istream& read (std::istream& in) {
            return in >> _x >> _y;}

        virtual std::ostream& write (std::ostream& out) const {
            return out << _x << " " << _y;}

    public:
        Shape (int x, int y) :
                _x (x),
                _y (y)
            {}

        virtual ~Shape ()
            {} //Destructor is also virtual which automatically makes class virtual

/*
        Shape (const Shape& that) :
                _x (that._x),
                _y (that._y)
            {}

        Shape& operator = (const Shape& that) {
            _x = that._x;
            _y = that._y;
            return *this;}

        template <typename T>       // doesn't compile
        virtual double f () const {
            return 0;}
*/

        virtual double area () const {
            return 0;}
//move is final in java but in c++ you can potentially override it (you should have a shape pointer to avoid this though)
        void move (int x, int y) {
            _x = x;
            _y = y;}};

class Circle : public Shape {
    private:
        int _r;

    protected:
        virtual bool equals (const Shape& that) const { //Need a Shape again in equals and then you must cast it into a Circle
            if (const Circle* const p = dynamic_cast<const Circle*>(&that)) //dynamic cast is only used when there's a virtual
                return Shape::equals(*p) && (_r == p->_r);
            return false;}

        virtual std::istream& read (std::istream& in) {
            return Shape::read(in) >> _r;}

        virtual std::ostream& write (std::ostream& out) const {
            return Shape::write(out) << " " << _r;}

    public:
        Circle (int x, int y, int r) :
                Shape (x, y),
                _r    (r)
            {}
/*
        Circle (const Circle& that) :
                Shape (that),
                _r    (that.r)
            {}

        ~Circle ()
            {}

        Circle& operator = (const Circle& that) {
            Shape::operator=(that);
            _r = that.r;
            return *this;}
*/

        virtual double area () const {
            return 3.14 * _r * _r;}

        int radius () const {
            return _r;}};

struct A {
    double _x;
    virtual void f () {}};

struct B : A {
    double _y;
    double _z;};

int main () {
    using namespace std;
    cout << "DynamicBinding.c++" << endl;

    {
    Shape x(2, 3);
    x.move(4, 5);
    assert(x.area()   == 0); //we know it's a shape so area and == are shape's
//  assert(x.radius() == 0); // doesn't compile
    }

    {
    const Shape x(2, 3);
          Shape y(4, 5);
    assert(x != y);
    y = x;
    assert(x == y);
    }

    {
    Circle x(2, 3, 4);
    x.move(5, 6);
    assert(x.area()   == 3.14 * 4 * 4);
    assert(x.radius() == 4);
    }

    {
    const Circle x(2, 3, 4);
          Circle y(2, 3, 5);
    assert(x != y);
    y = x;
    assert(x == y);
    }

    {
//  Circle* const p = new Shape(2, 3);              // doesn't compile
    Shape*  const p = new Circle(2, 3, 4);
    p->move(5, 6);
    assert(p->area()        == 3.14 * 4 * 4); //dynamic binding bc it's virtual
    assert(p->Shape::area() == 0);
//  assert(p->radius() == 4);                       // doesn't compile
    if (Circle* const q = dynamic_cast<Circle*>(p)) //dynamic casting also helps determine if p is a circle
        assert(q->radius() == 4);
    try {
        Circle& r = dynamic_cast<Circle&>(*p);
        assert(r.radius() == 4);}
    catch (const bad_cast& e) {
        assert(false);}
    delete p;
    }

    {
    const Shape* const p = new Circle(2, 3, 4);
          Shape* const q = new Circle(2, 3, 5);
    assert(*p != *q); 
//  *q = *p;             // illdefined //slicing happens again
    if (const Circle* const r = dynamic_cast<const Circle*>(p))
        if (Circle* const s = dynamic_cast<Circle*>(q))
            *s = *r;
    assert(*p == *q);
    delete p;
    delete q;
    }

    {
//  const Circle a[] = {Shape(2, 3), Circle(4, 5, 6)}; // doesn't compile
    const Shape  a[] = {Shape(2, 3), Circle(4, 5, 6)};
    assert(a[0].area() == 0);
    assert(a[1].area() == 0);
    }

    {
    const Circle a[] = {Circle(2, 3, 4), Circle(5, 6, 7)};
    assert(a[0].area() == 3.14 * 4 * 4);
    assert(a[1].area() == 3.14 * 7 * 7);
    const Shape* const p = a;
    assert(p[0].area() == 3.14 * 4 * 4);
//  assert(p[1].area() == 0);                              // illdefined
    }

    {
    assert(sizeof(A) == sizeof(void*) +     sizeof(double));
    assert(sizeof(B) == sizeof(A)     + 2 * sizeof(double));
    B t;
    char* p = reinterpret_cast<char*>(&t);
    char* x = reinterpret_cast<char*>(&t._x);
    char* y = reinterpret_cast<char*>(&t._y);
    char* z = reinterpret_cast<char*>(&t._z);
    assert(p + sizeof(void*)  == x);
    assert(x + sizeof(double) == y);
    assert(y + sizeof(double) == z);
    }

    cout << "Done." << endl;
    return 0;}
