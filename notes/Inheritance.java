// ----------------
// Inheritance.java
// ----------------

import java.util.ArrayList;

class Shape {
    private int _x;
    private int _y;

    public Shape (int x, int y) {
        _x = x;
        _y = y;}

    public double area () {
        return 0;}

    public boolean equals (Object rhs) { 
    //Since you need to override the equals method of Object the parameter is an Object
        if (!(rhs instanceof Shape)) 
        //But then you check if it's a shape
            return false;
        Shape that = (Shape) rhs; 
        //Since rhs is a Shape you can cast it //This gives you access to its _x and _y
        return (_x == that._x) && (_y == that._y);}
        //_x and _y are attributes of Shape

    public final void move (int x, int y) { 
    //You don't want anyone to override move which is why it's final
        _x = x;
        _y = y;}

    public String toString () {
        return _x + ", " + _y;}}

class Circle extends Shape {
    private int _r;

    public Circle (int x, int y, int r) { 
        //_x and _y must have the same relevant position as in the super class
        super(x, y); 
        //If this wasn't there it won't compile because Shape doesn't have a default constructor
        _r = r;}

    public double area () {
        return 3.14 * _r * _r;}

    public boolean equals (Object rhs) {
        if (rhs instanceof Circle)
            return super.equals(rhs) && (_r == ((Circle) rhs)._r);
        return false;}

    public int radius () {
        return _r;}

    public String toString () {
        return "(" + super.toString() + ", " + _r + ")";}}

final class Inheritance {
    public static void main (String[] args) {
        System.out.println("Inheritance.java");

        {
        final Shape x = new Shape(2, 3);
        assert x.area()     == 0;
        x.move(5, 6);
//      assert x.radius()   == 0;           // error: cannot find symbol
        assert x.toString().equals("5, 6");
        }

        {
        final Shape x = new Shape(2, 3);
        final Shape y = new Shape(2, 3);
        assert x != y;
        assert x.equals(y);
        }

        {
        final Circle x = new Circle(2, 3, 4);
        assert x.area()   == 3.14 * 4 * 4;
        x.move(5, 6);
        assert x.radius() == 4;
        assert x.toString().equals("(5, 6, 4)");
        }

        {
        final Circle x = new Circle(2, 3, 4);
        final Circle y = new Circle(2, 3, 4);
        assert x != y;
        assert x.equals(y);
        }


        {
//      final Circle x = new Shape(2, 3);             // error: incompatible types
        final Shape  x = new Circle(2, 3, 4); 
        //You can only see Circle's Shape qualities
        assert x.area()              == 3.14 * 4 * 4; 
        //calls circle's area bc Java is dynamically bound
        x.move(5, 6); //Statically bound
//      assert x.radius()            == 0;            // error: cannot find symbol 
        assert ((Circle) x).radius() == 4;
        assert x.toString().equals("(5, 6, 4)");
        }

        {
        final Shape x = new Circle(2, 3, 4);
        final Shape y = new Circle(2, 3, 4);
        assert x != y;
        assert x.equals(y);
        }

        {
//      final Circle[] a = {new Shape(2, 3), new Circle(2, 3, 4)}; // error: incompatible types
        final Shape[]  a = {new Shape(2, 3), new Circle(2, 3, 4)};
        //There's no slicing but this wouldn't work in c++
        assert a[0].area() == 0;
        assert a[1].area() == 3.14 * 4 * 4;
        }

        {
        final Shape[]          a = new Circle[3]; //Arrays are covariant
//      final ArrayList<Shape> x = new ArrayList<Circle>(10); // error: incompatible types
        //^Doesn't work but you can still create an arraylist of shapes and add circles to it later
        }

        System.out.println("Done.");}}
        