/*
CS371p: Quiz #29 (5 pts)
*/

class Shape {
    private:
        int _x;
        int _y;

    public:
        virtual ... equals (...) {...}
    ...};

class Circle : public Shape {
    private:
        int _r;
    ...};

/* -----------------------------------------------------------------------
1. Define Circle::Circle(...) in terms of Shape::Shape(...).
   (2 pts)
*/

Circle (int x, int y, int r) :
        Shape(x, y) {
    _r = r;}

/* -----------------------------------------------------------------------
2. Define Circle::equals(...) in terms of Shape::equals(...).
   (2 pts)
*/

bool equals (const Shape& that) const {
    if (const Circle* const p = dynamic_cast<const Circle*>(&that))
        return Shape::equals(*p) && (_r == p->_r);
    return false;}
