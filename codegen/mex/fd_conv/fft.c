/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * fft.c
 *
 * Code generation for function 'fft'
 *
 */

/* Include files */
#include "fft.h"
#include "fd_conv_data.h"
#include "fd_conv_emxutil.h"
#include "fd_conv_types.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo d_emlrtRSI = { 63,  /* lineNo */
  "fft",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\datafun\\fft.m"/* pathName */
};

static emlrtRTEInfo emlrtRTEI = { 37,  /* lineNo */
  31,                                  /* colNo */
  "fft",                               /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\datafun\\fft.m"/* pName */
};

static emlrtRTEInfo h_emlrtRTEI = { 63,/* lineNo */
  5,                                   /* colNo */
  "fft",                               /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\datafun\\fft.m"/* pName */
};

static emlrtRTEInfo i_emlrtRTEI = { 26,/* lineNo */
  32,                                  /* colNo */
  "MATLABFFTWCallback",                /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+fft\\MATLABFFTWCallback.m"/* pName */
};

/* Function Definitions */
void fft(const emlrtStack *sp, const emxArray_real_T *x, emxArray_creal_T *y)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  int32_T i;
  int32_T loop_ub;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  if (x->size[0] == 1) {
    emlrtErrorWithMessageIdR2018a(sp, &emlrtRTEI,
      "Coder:toolbox:autoDimIncompatibility",
      "Coder:toolbox:autoDimIncompatibility", 0);
  }

  st.site = &d_emlrtRSI;
  if (x->size[0] == 0) {
    i = y->size[0];
    y->size[0] = x->size[0];
    emxEnsureCapacity_creal_T(&st, y, i, &h_emlrtRTEI);
    loop_ub = x->size[0];
    for (i = 0; i < loop_ub; i++) {
      y->data[i].re = 0.0;
      y->data[i].im = 0.0;
    }
  } else {
    b_st.site = &e_emlrtRSI;
    c_st.site = &f_emlrtRSI;
    d_st.site = &g_emlrtRSI;
    e_st.site = &h_emlrtRSI;
    emlrtFFTWSetNumThreads(6);
    i = y->size[0];
    y->size[0] = x->size[0];
    emxEnsureCapacity_creal_T(&e_st, y, i, &i_emlrtRTEI);
    emlrtFFTW_1D_R2C(&x->data[0], (real_T *)&y->data[0], 1, x->size[0], x->size
                     [0], 1, -1);
  }
}

/* End of code generation (fft.c) */
