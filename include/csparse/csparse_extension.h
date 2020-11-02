#ifndef FBLOCKSOLVER_CSPARSE_EXTENSION_H
#define FBLOCKSOLVER_CSPARSE_EXTENSION_H

#ifndef NCOMPLEX
#define NCOMPLEX
#endif
#include <cs.h>
#include "../base/afxdef.h"

#include "fblock_solver_csparse_extension_api.h"

namespace FblockSolver {

  namespace csparse_extension {

// our extensions to csparse
// Copyright (C) 2011 R. Kuemmerle, G. Grisetti, W. Burgard
  /**
   * Originally from CSparse, avoid memory re-allocations by giving workspace pointers
   * CSparse: Copyright (c) 2006-2011, Timothy A. Davis.
   */
FBLOCKSOLVER_CSPARSE_EXTENSION_API csn* cs_chol_workspace (const cs *A, const css *S, int* cin, number_t* xin);
FBLOCKSOLVER_CSPARSE_EXTENSION_API int cs_cholsolsymb(const cs *A, number_t *b, const css* S, number_t* workspace, int* work);

} // end namespace
} // end namespace

#endif
