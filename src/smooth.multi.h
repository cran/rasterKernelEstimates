#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#if defined _OPENMP
  #include <omp.h>
#endif


#include <R.h>
#include <Rmath.h>
#include <Rinternals.h>


// find the maximum value
static inline double maxDouble( double * A, const size_t n); 

  // find the minimum value 
static inline double minDouble( double * A, const size_t n);

/* swap function */
static inline void swap( double * A, const size_t b, const size_t c);

/* partition function */
static inline size_t partition( double * A, const size_t left, const size_t right, const size_t pivot);

//Quickselect
// right should be equal to n-1 and left should be 0 when searching all of A
static inline double quantile_quickSelect( double * A, size_t left, size_t right, const size_t k);

/* integer max */
int intMax ( int x, int y);

/* integer min */
int intMin ( int x, int y);


/* modal kernel */
double modalKernel(
    int * x,    /* raster image */
    double * W,    /* pre computed spatial weights */
    size_t i,      /* current location in columns */
    size_t j,      /* current location in rows */
    size_t dRow,
    size_t dCol,
    size_t nRow,   /* number of Rows */
    size_t nCol    /* number of Columns */
  );


/* quantile kernel */
double quantileKernel(
    double * x,    /* naip image */
    double * W,    /* pre computed spatial weights */
    double quantile,      /* quantile */
    size_t i,      /* current location in columns */
    size_t j,      /* current location in rows */
    size_t dRow,
    size_t dCol,
    size_t nRow,   /* number of Rows */
    size_t nCol    /* number of Columns */
  );

/* generic kernel */
double meanKernel(
    double * x,    /* naip image */
    double * var,  /*  */
    double * W,    /* pre computed spatial weights */
    size_t i,      /* current location in columns */
    size_t j,      /* current location in rows */
    size_t dRow,
    size_t dCol,
    size_t nRow,   /* number of Rows */
    size_t nCol    /* number of Columns */
  );



/* generic kernel */
double gaussianKernel(
    double * x,    /* naip image */
    double hInv,    /* pre computed spatial weights */
    size_t i,      /* current location in columns */
    size_t j,      /* current location in rows */
    size_t dRow,
    size_t dCol,
    size_t nRow,   /* number of Rows */
    size_t nCol    /* number of Columns */
  );


/* variance kernel */
double varKernel(
    double * x,    /* naip image */
    double * mu,  /*  */
    double * W,    /* pre computed spatial weights */
    size_t i,      /* current location in columns */
    size_t j,      /* current location in rows */
    size_t dRow,
    size_t dCol,
    size_t nRow,   /* number of Rows */
    size_t nCol    /* number of Columns */
  );


void rSmoothLocalMoments( 
    double * x,         /* this is the multi year naip images  */ 
    double * mu,        /* this is the input/returned mu */ 
    double * var,        /* this is the input/returned Var */ 
    double * WMu,      /* weight */
    double * WVar,      /* weight */
    int * nRowPtr, 
    int * nColPtr,
    int * dRowPtr, 
    int * dColPtr,
    int * momentsPtr
    );


void rSmoothCategorical( 
    int * x,         /* this is the multi year naip images  */ 
    int * mu,        /* this is the input/returned mu */ 
    double * WMu,      /* weight */
    int * nRowPtr, 
    int * nColPtr,
    int * dRowPtr, 
    int * dColPtr
    ); 
 

void rSmoothLocalQuantile( 
    double * x,         /* this is the multi year naip images  */ 
    double * mu,        /* this is the input/returned mu */ 
    double * WMu,      /* weight */
    double * quantile, /* quantile */
    int * nRowPtr, 
    int * nColPtr,
    int * dRowPtr, 
    int * dColPtr
    );
