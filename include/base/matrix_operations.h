#ifndef FBLOCKSOLVER_CORE_MATRIX_OPERATIONS_H
#define FBLOCKSOLVER_CORE_MATRIX_OPERATIONS_H

#include <Eigen/Core>
#include "afxdef.h"

namespace FblockSolver {
  namespace internal {

    template<typename MatrixType>
    inline void axpy(const MatrixType& A, const Eigen::Map<const VectorX>& x, int xoff, Eigen::Map<VectorX>& y, int yoff)
    {
      y.segment<MatrixType::RowsAtCompileTime>(yoff) += A * x.segment<MatrixType::ColsAtCompileTime>(xoff);
    }

    template<int t>
    inline void axpy(const Eigen::Matrix<number_t, Eigen::Dynamic, t>& A, const Eigen::Map<const VectorX>& x, int xoff, Eigen::Map<VectorX>& y, int yoff)
    {
      y.segment(yoff, A.rows()) += A * x.segment<Eigen::Matrix<number_t, Eigen::Dynamic, t>::ColsAtCompileTime>(xoff);
    }

    template<>
    inline void axpy<MatrixX>(const MatrixX& A, const Eigen::Map<const VectorX>& x, int xoff, Eigen::Map<VectorX>& y, int yoff)
    {
      y.segment(yoff, A.rows()) += A * x.segment(xoff, A.cols());
    }

    template<typename MatrixType>
    inline void atxpy(const MatrixType& A, const Eigen::Map<const VectorX>& x, int xoff, Eigen::Map<VectorX>& y, int yoff)
    {
      y.segment<MatrixType::ColsAtCompileTime>(yoff) += A.transpose() * x.segment<MatrixType::RowsAtCompileTime>(xoff);
    }

    template<int t>
    inline void atxpy(const Eigen::Matrix<number_t, Eigen::Dynamic, t>& A, const Eigen::Map<const VectorX>& x, int xoff, Eigen::Map<VectorX>& y, int yoff)
    {
      y.segment<Eigen::Matrix<number_t, Eigen::Dynamic, t>::ColsAtCompileTime>(yoff) += A.transpose() * x.segment(xoff, A.rows());
    }

    template<>
    inline void atxpy<MatrixX>(const MatrixX& A, const Eigen::Map<const VectorX>& x, int xoff, Eigen::Map<VectorX>& y, int yoff)
    {
      y.segment(yoff, A.cols()) += A.transpose() * x.segment(xoff, A.rows());
    }

  } // end namespace internal
} // end namespace FBLOCKSOLVER

#endif
