// ------------------------
// FunctionOverloading.java
// ------------------------

// ad-hoc compile-time polymorphism

class A { // does NOT implement Comparable
    private int _i;

    public A (int i) {
        _i = i;}

    public int compareTo (A that) {
        return _i - that._i;}}

class B extends A {
    public B (int n) {
        super(n);}}

final class FunctionOverloading {
    private static String f (int i) {
        return "f(int)";}

    private static String f (long l) {
        return "f(long)";}

    private static String f (A x) {
        return "f(A)";}

    private static String f (B y) {
        return "f(B)";}

    private static String g (int i) {
        return "g(int)";}

    private static String h (double d) {
        return "h(double)";}

    private static int myMax (int x, int y) {
        if (x < y)
            return y;
        return x;}

    private static String myMax (String x, String y) {
        if (x.compareTo(y) < 0)
            return y;
        return x;}

    private static A myMax (A x, A y) {
        if (x.compareTo(y) < 0)
            return y;
        return x;}

    public static void main (String[] args) {
        System.out.println("FunctionOverloading.java");

        assert f(2)  == "f(int)";
        assert f(3L) == "f(long)";

        assert f(new A(2)) == "f(A)";
        assert f(new B(3)) == "f(B)";

        assert g(2)   == "g(int)";
//      assert g(2.3) == "g(int)"; // g(int) in FunctionOverloading cannot be applied to (double)

        assert h(2)   == "h(double)";
        assert h(2.3) == "h(double)";

        assert myMax(2,   3)   == 3;
//      assert myMax(2.3, 4)   == 4; // doesn't compile
//      assert myMax(2,   3.4) == 3; // doesn't compile
//      assert myMax(2.3, 4.5) == 5; // doesn't compile

        assert Math.max(2,   3)   == 3;
        assert Math.max(2.3, 4)   == 4;
        assert Math.max(2,   3.4) == 3.4;
        assert Math.max(2.3, 4.5) == 4.5;

        assert myMax("abc", "def") == "def";

        {
        A x = new A(2);
        A y = new A(3);
        assert myMax(x, y) == y;
        }

        {
        B x = new B(2);
        B y = new B(3);
        assert myMax(x, y) == y;
        }

        System.out.println("Done.");}}
