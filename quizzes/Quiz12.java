/*
CS371p: Quiz #12 (5 pts)
*/

/* -----------------------------------------------------------------------
1. Define the method arraycopy(), iteratively, such that it mimics
   System.arraycopy().
   (4 pts)
*/

import java.util.Arrays;

class Quiz12 {
    public static void arraycopy (long[] a, int i, long[] b, int j, int s) {
        if (j < i) {
            int n = 0;
            while (n != s) {
                b[j + n] = a[i + n];
                ++n;}}
        else {
            int n = s;
            while (n != 0) {
                --n;
                b[j + n] = a[i + n];}}}

    public static void main (String[] args) {
        {
        final long[] a = {2, 3, 4};
        arraycopy(a, 0, a, 1, 2);
        assert Arrays.equals(a, new long[]{2, 2, 3});
        }

        {
        final long[] a = {2, 3, 4};
        arraycopy(a, 1, a, 0, 2);
        assert Arrays.equals(a, new long[]{3, 4, 4});
        }}}
