/* Copyright (c) 2015-2016  Jonathan Lisic 
 * Last edit: 16/08/24 - 09:20:44
 * License: GPL (>=2) 
 */  

#include <stdio.h> 
#include <stdlib.h>

#if defined _OPENMP
  #include <omp.h>
#endif

#include "R.h"
#include "Rinternals.h"
#include "Rmath.h"
#include <R_ext/Rdynload.h>
#include "smooth.multi.h"
#include "sum.h"




/***********************************/
/* Register SO's                   */

static R_NativePrimitiveArgType R_SmoothLocalMoments_t[] = {
      REALSXP, REALSXP, REALSXP, REALSXP, REALSXP, 
      INTSXP, INTSXP, INTSXP, INTSXP, INTSXP
};

static R_NativePrimitiveArgType R_SmoothCategorical_t[] = {
      INTSXP, INTSXP,
      REALSXP, 
      INTSXP, INTSXP, INTSXP, INTSXP
};

static R_NativePrimitiveArgType R_SmoothLocalQuantile_t[] = {
      REALSXP, REALSXP, REALSXP, REALSXP, 
      INTSXP, INTSXP, INTSXP, INTSXP
};

static R_NativePrimitiveArgType R_SmoothSums_t[] = {
      REALSXP, REALSXP, REALSXP, 
      INTSXP, INTSXP, INTSXP, INTSXP
};



static const R_CMethodDef cMethods[] = {
     {"rSmoothLocalMoments", (DL_FUNC) &rSmoothLocalMoments, 10, R_SmoothLocalMoments_t},
     {"rSmoothCategorical", (DL_FUNC) &rSmoothCategorical, 7, R_SmoothCategorical_t},
     {"rSmoothLocalQuantile", (DL_FUNC) &rSmoothLocalQuantile, 8, R_SmoothLocalQuantile_t},
     {"rSmoothSums", (DL_FUNC) &rSmoothSums, 7, R_SmoothSums_t},
     {NULL, NULL, 0}
};

void R_init_myLib(DllInfo *info)
{
     R_registerRoutines(info, cMethods, NULL, NULL, NULL);
     R_useDynamicSymbols(info, TRUE); 
}



