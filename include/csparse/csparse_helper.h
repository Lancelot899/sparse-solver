#ifndef FBLOCKSOLVER_CSPARSE_HELPER_H
#define FBLOCKSOLVER_CSPARSE_HELPER_H

#include "csparse_extension.h"

#include "fblock_solver_csparse_extension_api.h"

namespace FblockSolver {

  namespace csparse_extension {

/**
 * write the sparse matrix to a file loadable with ocatve
 */
FBLOCKSOLVER_CSPARSE_EXTENSION_API bool writeCs2Octave(const char* filename, const cs* A, bool upperTriangular = true);

} // end namespace
} // end namespace

#endif
