# fast block solver
this solver is almost from g2o. We use its spasre linear solvers to build this library.

## dependence
this library need [suitesparse](https://people.engr.tamu.edu/davis/suitesparse.html).
you can install it with:

```

sudo apt install libsuitesparse-dev (ubuntu)
brew install suite-sparse (mac)

```

## how to use
you can see the test directory to learn how to use.

### build linear system
you can use this api to construct a linear system.
```
SparseBlockMatrix( const int * rbi, const int* cbi, int rb, int cb, bool hasStorage=true);
```

the first param is sum of the block size of each rows in the system. e.g. int rbi[] = {3, 6, 9} means the size of first row is 3 and the size of second row is 6 - 3 = 3.

the second param is sum of the block size of each cols in the system. e.g. int cbi[] = {3, 6, 9} means the size of first col is 3 and the size of second col is 6 - 3 = 3.

the third param is the number of blocks of row

the third param is the number of blocks of col


----------------------------------------------------------------

then you can fill this system use block function like the test demo.

### solver
there are three solvers in this library. 