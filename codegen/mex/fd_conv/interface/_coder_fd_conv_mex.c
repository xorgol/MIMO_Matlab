/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_fd_conv_mex.c
 *
 * Code generation for function '_coder_fd_conv_mex'
 *
 */

/* Include files */
#include "_coder_fd_conv_mex.h"
#include "_coder_fd_conv_api.h"
#include "fd_conv_data.h"
#include "fd_conv_initialize.h"
#include "fd_conv_terminate.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void fd_conv_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs, const
  mxArray *prhs[2])
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  const mxArray *outputs[1];
  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 2, 4, 7,
                        "fd_conv");
  }

  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 7,
                        "fd_conv");
  }

  /* Call the function. */
  fd_conv_api(prhs, outputs);

  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, plhs, outputs);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  mexAtExit(&fd_conv_atexit);

  /* Module initialization. */
  fd_conv_initialize();

  /* Dispatch the entry-point. */
  fd_conv_mexFunction(nlhs, plhs, nrhs, prhs);

  /* Module termination. */
  fd_conv_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_fd_conv_mex.c) */
