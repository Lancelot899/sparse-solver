#ifndef FBLOCKSOLVER_LINEAR_SOLVER_PCG_H
#define FBLOCKSOLVER_LINEAR_SOLVER_PCG_H

#include "base/linear_solver.h"

#include <vector>
#include <utility>
#include<Eigen/Core>

namespace FblockSolver {

  /**
   * \brief linear solver using PCG, pre-conditioner is block Jacobi
   */
  template <typename MatrixType>
  class LinearSolverPCG : public LinearSolver<MatrixType>
  {
    public:
      LinearSolverPCG() :
      LinearSolver<MatrixType>()
      {
        _tolerance = cst(1e-6);
        _verbose = false;
        _absoluteTolerance = true;
        _residual = -1.0;
        _maxIter = -1;
      }

      virtual ~LinearSolverPCG()
      {
      }

      virtual bool init()
      {
        _residual = -1.0;
        _indices.clear();
        _sparseMat.clear();
        return true;
      }

      bool solve(const SparseBlockMatrix<MatrixType>& A, number_t* x, number_t* b);

      //! return the tolerance for terminating PCG before convergence
      number_t tolerance() const { return _tolerance;}
      void setTolerance(number_t tolerance) { _tolerance = tolerance;}

      int maxIterations() const { return _maxIter;}
      void setMaxIterations(int maxIter) { _maxIter = maxIter;}

      bool absoluteTolerance() const { return _absoluteTolerance;}
      void setAbsoluteTolerance(bool absoluteTolerance) { _absoluteTolerance = absoluteTolerance;}

      bool verbose() const { return _verbose;}
      void setVerbose(bool verbose) { _verbose = verbose;}

    protected:
      typedef std::vector< MatrixType, Eigen::aligned_allocator<MatrixType> > MatrixVector;
      typedef std::vector< const MatrixType* > MatrixPtrVector;

      number_t _tolerance;
      number_t _residual;
      bool _absoluteTolerance;
      bool _verbose;
      int _maxIter;

      MatrixPtrVector _diag;
      MatrixVector _J;

      std::vector<std::pair<int, int> > _indices;
      MatrixPtrVector _sparseMat;

      void multDiag(const std::vector<int>& colBlockIndices, MatrixVector& A, const VectorX& src, VectorX& dest);
      void multDiag(const std::vector<int>& colBlockIndices, MatrixPtrVector& A, const VectorX& src, VectorX& dest);
      void mult(const std::vector<int>& colBlockIndices, const VectorX& src, VectorX& dest);
  };

#include "linear_solver_pcg.hpp"

}// end namespace

#endif
