#include <Eigen/Dense>
#include "cholmod/linear_solver_cholmod.h"
#include <iostream>

int main(int argc, char *argv[]) {
    int rbi[3] = {3, 6, 9};
    int cbi[3] = {3, 6, 9};
    FblockSolver::SparseBlockMatrix<Eigen::Matrix3d> A(rbi, cbi, 3, 3);
    Eigen::Matrix<double, 9, 9> Ae;
    Ae.setZero();
    FblockSolver::LinearSolverCholmod<Eigen::Matrix3d> solver;
    Ae.block<3, 3>(0, 0) = *A.block(0, 0, true) = 3 * Eigen::Matrix3d::Identity();
    Ae.block<3, 3>(3, 3) = *A.block(1, 1, true) = 3 * Eigen::Matrix3d::Identity();
    Ae.block<3, 3>(6, 6) = *A.block(2, 2, true) = 3 * Eigen::Matrix3d::Identity();
    Ae.block<3, 3>(0, 3) = *A.block(0, 1, true) = -Eigen::Matrix3d::Identity();
    Ae.block<3, 3>(3, 0) = *A.block(1, 0, true) = -Eigen::Matrix3d::Identity();
    Ae.block<3, 3>(6, 3) = *A.block(2, 1, true) = -Eigen::Matrix3d::Identity();
    Ae.block<3, 3>(3, 6) = *A.block(1, 2, true) = -Eigen::Matrix3d::Identity();

    double *b = new double[9 * sizeof(double)];
    Eigen::Map<Eigen::Matrix<double, 9, 1> >b_(b);
    b_ = Eigen::Matrix<double, 9, 1>::Ones();
    double *x = new double[9 * sizeof(double)];
    solver.solve(A, x, b);
    Eigen::Map<Eigen::Matrix<double, 9, 1> >x_(x);
    std::cout << "x  = " << x_.transpose() << std::endl;
    Eigen::Matrix<double, 9, 1> xe = Ae.ldlt().solve(b_);
    std::cout << "xe = " << xe.transpose() << std::endl;
    return 0;
}