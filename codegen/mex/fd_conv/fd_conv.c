/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * fd_conv.c
 *
 * Code generation for function 'fd_conv'
 *
 */

/* Include files */
#include "fd_conv.h"
#include "fd_conv_emxutil.h"
#include "fd_conv_types.h"
#include "fft.h"
#include "ifft.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 10,    /* lineNo */
  "fd_conv",                           /* fcnName */
  "C:\\Users\\prude\\OneDrive\\Documenti\\GitHub\\MIMO_Matlab\\Lib\\fd_conv.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 11,  /* lineNo */
  "fd_conv",                           /* fcnName */
  "C:\\Users\\prude\\OneDrive\\Documenti\\GitHub\\MIMO_Matlab\\Lib\\fd_conv.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 14,  /* lineNo */
  "fd_conv",                           /* fcnName */
  "C:\\Users\\prude\\OneDrive\\Documenti\\GitHub\\MIMO_Matlab\\Lib\\fd_conv.m"/* pathName */
};

static emlrtDCInfo emlrtDCI = { 8,     /* lineNo */
  20,                                  /* colNo */
  "fd_conv",                           /* fName */
  "C:\\Users\\prude\\OneDrive\\Documenti\\GitHub\\MIMO_Matlab\\Lib\\fd_conv.m",/* pName */
  4                                    /* checkKind */
};

static emlrtECInfo emlrtECI = { -1,    /* nDims */
  12,                                  /* lineNo */
  6,                                   /* colNo */
  "fd_conv",                           /* fName */
  "C:\\Users\\prude\\OneDrive\\Documenti\\GitHub\\MIMO_Matlab\\Lib\\fd_conv.m"/* pName */
};

static emlrtRTEInfo b_emlrtRTEI = { 7, /* lineNo */
  1,                                   /* colNo */
  "fd_conv",                           /* fName */
  "C:\\Users\\prude\\OneDrive\\Documenti\\GitHub\\MIMO_Matlab\\Lib\\fd_conv.m"/* pName */
};

static emlrtRTEInfo c_emlrtRTEI = { 8, /* lineNo */
  6,                                   /* colNo */
  "fd_conv",                           /* fName */
  "C:\\Users\\prude\\OneDrive\\Documenti\\GitHub\\MIMO_Matlab\\Lib\\fd_conv.m"/* pName */
};

static emlrtRTEInfo d_emlrtRTEI = { 11,/* lineNo */
  1,                                   /* colNo */
  "fd_conv",                           /* fName */
  "C:\\Users\\prude\\OneDrive\\Documenti\\GitHub\\MIMO_Matlab\\Lib\\fd_conv.m"/* pName */
};

static emlrtRTEInfo e_emlrtRTEI = { 12,/* lineNo */
  6,                                   /* colNo */
  "fd_conv",                           /* fName */
  "C:\\Users\\prude\\OneDrive\\Documenti\\GitHub\\MIMO_Matlab\\Lib\\fd_conv.m"/* pName */
};

static emlrtRTEInfo f_emlrtRTEI = { 10,/* lineNo */
  1,                                   /* colNo */
  "fd_conv",                           /* fName */
  "C:\\Users\\prude\\OneDrive\\Documenti\\GitHub\\MIMO_Matlab\\Lib\\fd_conv.m"/* pName */
};

static emlrtRTEInfo g_emlrtRTEI = { 11,/* lineNo */
  6,                                   /* colNo */
  "fd_conv",                           /* fName */
  "C:\\Users\\prude\\OneDrive\\Documenti\\GitHub\\MIMO_Matlab\\Lib\\fd_conv.m"/* pName */
};

/* Function Definitions */
void fd_conv(const emlrtStack *sp, const emxArray_real_T *a, const real_T b
             [480000], emxArray_creal_T *c)
{
  emlrtStack st;
  emxArray_creal_T *fa;
  emxArray_creal_T *fb;
  emxArray_creal_T *r;
  emxArray_real_T *b_b;
  emxArray_real_T *pa;
  real_T im;
  int32_T i;
  int32_T loop_ub;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &pa, 1, &b_emlrtRTEI, true);
  i = pa->size[0];
  pa->size[0] = a->size[0] + 479999;
  emxEnsureCapacity_real_T(sp, pa, i, &b_emlrtRTEI);
  loop_ub = a->size[0];
  for (i = 0; i < loop_ub; i++) {
    pa->data[i] = a->data[i];
  }

  for (i = 0; i < 479999; i++) {
    pa->data[i + a->size[0]] = 0.0;
  }

  if (!((((real_T)a->size[0] + 480000.0) - 1.0) - 480000.0 >= 0.0)) {
    emlrtNonNegativeCheckR2012b((((real_T)a->size[0] + 480000.0) - 1.0) -
      480000.0, &emlrtDCI, sp);
  }

  emxInit_creal_T(sp, &fa, 1, &f_emlrtRTEI, true);
  emxInit_real_T(sp, &b_b, 1, &c_emlrtRTEI, true);
  st.site = &emlrtRSI;
  fft(&st, pa, fa);
  i = b_b->size[0];
  b_b->size[0] = a->size[0] + 479999;
  emxEnsureCapacity_real_T(sp, b_b, i, &c_emlrtRTEI);
  emxFree_real_T(&pa);
  for (i = 0; i < 480000; i++) {
    b_b->data[i] = b[i];
  }

  loop_ub = a->size[0] - 1;
  for (i = 0; i < loop_ub; i++) {
    b_b->data[i + 480000] = 0.0;
  }

  emxInit_creal_T(sp, &fb, 1, &d_emlrtRTEI, true);
  emxInit_creal_T(sp, &r, 1, &g_emlrtRTEI, true);
  st.site = &b_emlrtRSI;
  fft(&st, b_b, r);
  i = fb->size[0];
  fb->size[0] = r->size[0];
  emxEnsureCapacity_creal_T(sp, fb, i, &d_emlrtRTEI);
  loop_ub = r->size[0];
  emxFree_real_T(&b_b);
  for (i = 0; i < loop_ub; i++) {
    fb->data[i] = r->data[i];
  }

  emxFree_creal_T(&r);
  if (fa->size[0] != fb->size[0]) {
    emlrtSizeEqCheck1DR2012b(fa->size[0], fb->size[0], &emlrtECI, sp);
  }

  i = fb->size[0];
  fb->size[0] = fa->size[0];
  emxEnsureCapacity_creal_T(sp, fb, i, &e_emlrtRTEI);
  loop_ub = fa->size[0];
  for (i = 0; i < loop_ub; i++) {
    im = fa->data[i].re * fb->data[i].im + fa->data[i].im * fb->data[i].re;
    fb->data[i].re = fa->data[i].re * fb->data[i].re - fa->data[i].im * fb->
      data[i].im;
    fb->data[i].im = im;
  }

  emxFree_creal_T(&fa);
  st.site = &c_emlrtRSI;
  ifft(&st, fb, c);
  emxFree_creal_T(&fb);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (fd_conv.c) */
