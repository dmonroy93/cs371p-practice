/*
CS371p: Quiz #4 (5 pts)
*/

/* -----------------------------------------------------------------------
1. What does the Sapir-Whorf hypothesis assert?
   [Sec. 1.2.3, Pg. 5]
   (1 pt)

It may be possible for an individual working in one language to
imagine thoughts or utter ideas that cannot in any way be translated,
or even understood by individuals operating in a different linguistic
framework.
*/

/* -----------------------------------------------------------------------
2. Given positive integers, b and e, let m = e / 2. If b < m, then
   max_cycle_length(b, e) = max_cycle_length(m, e). True or False?
   [Collatz]
   (1 pt)

True

Consider b = 10, e = 100.
Then m = 100 / 2 = 50.
max_cycle_length(10, 100) = max_cycle_length(50, 100)
All the numbers in the range [10, 49] can be mapped to numbers in the
range [50, 100] by one or more doublings, so none of the numbers in the
range [10, 49] could have a larger cycle length than the numbers in the
range [50, 100].
*/

/* -----------------------------------------------------------------------
3. Describe the difference between a unit test and an acceptance test.
   (2 pts)

a unit test tests the return value and the side effects of an individual
function or method
an acceptance test tests the input/output behavior of the whole program
*/
