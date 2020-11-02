#ifndef FBLOCKSOLVER_EIGEN_TYPES_H
#define FBLOCKSOLVER_EIGEN_TYPES_H

#include <Eigen/Core>
#include <Eigen/Geometry>

namespace FblockSolver {

  typedef Eigen::Matrix<int,2,1,Eigen::ColMajor>                                  Vector2I;
  typedef Eigen::Matrix<int,3,1,Eigen::ColMajor>                                  Vector3I;
  typedef Eigen::Matrix<int,4,1,Eigen::ColMajor>                                  Vector4I;
  typedef Eigen::Matrix<int,Eigen::Dynamic,1,Eigen::ColMajor>                     VectorXI; 

  typedef Eigen::Matrix<float,2,1,Eigen::ColMajor>                                Vector2F; 
  typedef Eigen::Matrix<float,3,1,Eigen::ColMajor>                                Vector3F; 
  typedef Eigen::Matrix<float,4,1,Eigen::ColMajor>                                Vector4F; 
  typedef Eigen::Matrix<float,Eigen::Dynamic,1,Eigen::ColMajor>                   VectorXF;

  template<int N>
  using VectorN = Eigen::Matrix<number_t, N, 1, Eigen::ColMajor>;
  using Vector2 = VectorN<2>;
  using Vector3 = VectorN<3>;
  using Vector4 = VectorN<4>;
  using Vector6 = VectorN<6>;
  using Vector7 = VectorN<7>;
  using VectorX = VectorN<Eigen::Dynamic>;

  typedef Eigen::Matrix<int,2,2,Eigen::ColMajor>                                  Matrix2I;
  typedef Eigen::Matrix<int,3,3,Eigen::ColMajor>                                  Matrix3I;
  typedef Eigen::Matrix<int,4,4,Eigen::ColMajor>                                  Matrix4I;
  typedef Eigen::Matrix<int,Eigen::Dynamic,Eigen::Dynamic,Eigen::ColMajor>        MatrixXI;

  typedef Eigen::Matrix<float,2,2,Eigen::ColMajor>                                Matrix2F;
  typedef Eigen::Matrix<float,3,3,Eigen::ColMajor>                                Matrix3F;
  typedef Eigen::Matrix<float,4,4,Eigen::ColMajor>                                Matrix4F;
  typedef Eigen::Matrix<float,Eigen::Dynamic,Eigen::Dynamic,Eigen::ColMajor>      MatrixXF;

  template<int N>
  using MatrixN = Eigen::Matrix<number_t, N, N, Eigen::ColMajor>;
  using Matrix2 = MatrixN<2>;
  using Matrix3 = MatrixN<3>;
  using Matrix4 = MatrixN<4>;
  using MatrixX = MatrixN<Eigen::Dynamic>;

  typedef Eigen::Transform<number_t,2,Eigen::Isometry,Eigen::ColMajor>            Isometry2;
  typedef Eigen::Transform<number_t,3,Eigen::Isometry,Eigen::ColMajor>            Isometry3;

  typedef Eigen::Transform<number_t,2,Eigen::Affine,Eigen::ColMajor>              Affine2;
  typedef Eigen::Transform<number_t,3,Eigen::Affine,Eigen::ColMajor>              Affine3;

  typedef Eigen::Rotation2D<number_t>                                             Rotation2D;

  typedef Eigen::Quaternion<number_t>                                             Quaternion;

  typedef Eigen::AngleAxis<number_t>                                              AngleAxis;

} // end namespace FBLOCKSOLVER

#endif
