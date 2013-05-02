// --------------
// Arguments.java
// --------------

import java.util.Arrays;

final class Arguments {
    private static void f (int j) {
        ++j;}

    private static void g (String t) {
        t += "def";}

    private static void h (int[] b) {
        ++b[1];}

    public static void main (String[] args) {
        System.out.println("Arguments.java");

        {
        int i = 2;
        f(i);
        assert i == 2;
        }

        {
        String s = "abc";
        g(s);
        assert s.equals("abc");
        assert s == "abc";
        }

        {
        int[] a = {2, 3, 4};
        h(a);
        assert a != new int[]{2, 4, 4};
        assert !a.equals(new int[]{2, 4, 4});
        assert Arrays.equals(a, new int[]{2, 4, 4});
        }

        System.out.println("Done.");}}
