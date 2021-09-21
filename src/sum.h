
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#if defined _OPENMP
  #include <omp.h>
#endif



#include <R.h>
#include <Rmath.h>
#include <Rinternals.h>



double sumKernel(
    double * x,    /* naip image */
    double * W,    /* pre computed spatial weights */
    size_t i,      /* current location in columns */
    size_t j,      /* current location in rows */
    size_t dRow,
    size_t dCol,
    size_t nRow,   /* number of Rows */
    size_t nCol    /* number of Columns */
  );


void rSmoothSums( 
    double * x,         /* this is the multi year naip images  */ 
    double * mu,        /* this is the input/returned mu */ 
    double * WMu,      /* weight */
    int * nRowPtr, 
    int * nColPtr,
    int * dRowPtr, 
    int * dColPtr
    );

