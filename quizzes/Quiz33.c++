/*
CS371p: Quiz #33 (5 pts)
*/

/* -----------------------------------------------------------------------
1. Define Shape's constructor.
   (4 pts)
*/

struct Shape : Handle<AbstractShape> {
    Shape (AbstractShape* p) :
            Handle<AbstractShape> (p)
        {}
    ...};
