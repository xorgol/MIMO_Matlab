/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * fd_conv.h
 *
 * Code generation for function 'fd_conv'
 *
 */

#pragma once

/* Include files */
#include "fd_conv_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void fd_conv(const emlrtStack *sp, const emxArray_real_T *a, const real_T b
             [480000], emxArray_creal_T *c);

/* End of code generation (fd_conv.h) */
