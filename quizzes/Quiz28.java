/*
CS371p: Quiz #28 (5 pts)
*/

class Shape {
    private int _x;
    private int _y;

    public ... equals (...) {...}
    ...}

class Circle extends Shape {
    private int _r;
    ...}

/* -----------------------------------------------------------------------
1. Define Circle.Circle(...) in terms of Shape.Shape(...).
   (2 pts)
*/

public Circle (int x, int y, int r) {
    super(x, y);
    _r = r;}

/* -----------------------------------------------------------------------
2. Define Circle.equals(...) in terms of Shape.equals(...).
   (2 pts)
*/

public boolean equals (Object rhs) {
    if (rhs instanceof Circle)
        return super.equals(rhs) && (_r == ((Circle) rhs)._r);
    return false;}
