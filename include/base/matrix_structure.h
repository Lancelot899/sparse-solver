#ifndef FBLOCKSOLVER_MATRIX_STRUCTURE_H
#define FBLOCKSOLVER_MATRIX_STRUCTURE_H

#include "afxdef.h"

namespace FblockSolver {

/**
 * \brief representing the structure of a matrix in column compressed structure (only the upper triangular part of the matrix)
 */
class FBLOCKSOLVER_CORE_API MatrixStructure
{
  public:
    MatrixStructure();
    ~MatrixStructure();
    /**
     * allocate space for the Matrix Structure. You may call this on an already allocated struct, it will
     * then reallocate the memory + additional space (number_t the required space).
     */
    void alloc(int n_, int nz);

    void free();
    
    /**
     * Write the matrix pattern to a file. File is also loadable by octave, e.g., then use spy(matrix)
     */
    bool write(const char* filename) const;

    int n;    ///< A is m-by-n.  n must be >= 0.
    int m;    ///< A is m-by-n.  m must be >= 0.
    int* Ap;  ///< column pointers for A, of size n+1
    int* Aii; ///< row indices of A, of size nz = Ap [n]

    //! max number of non-zeros blocks
    int nzMax() const { return maxNz;}

  protected:
    int maxN;     ///< size of the allocated memory
    int maxNz;    ///< size of the allocated memory
};

} // end namespace

#endif
