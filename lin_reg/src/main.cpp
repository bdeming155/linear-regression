#include <iostream>
#include <Eigen/Dense>
#include "../include/linear_regression.h"


int main() {

  ArrayXXd X(3,2);
  X(0,0) = 3.7;
  X(1,0) = 4.6;
  X(0,1) = 2.4;
  X(1,1) = 0.98;
  X(2,0) = 0.78;
  X(2,1) = 0.12;
    //std::cout << m;

//    MatrixXd a3 = MatrixXd::Ones(2, 2);
//    std::cout<< a3;
//
//    MatrixXd C(m.rows(), m.cols()+a3.cols());
//    C << m, a3;
//
//    std::cout << m.cols(1) << std::endl;
//    std::cout << a3 << std::endl;
//    std::cout << C << std::endl;

//    Matrix2d mat;
//    mat << 1,2,3,4;
//    std::cout << mat.array().col(1) - mat.col(1).mean();

//    ArrayXXd u;
//    u = mat.array();
//    Matrix2d v = u.matrix();

    ArrayXXd y_train(3,1);
    y_train(0,0) = 0.43;
    y_train(1,0) = 0.98;
    y_train(2,0) = 0.4;


    Regression test(X, y_train, true);
    //std::cout << test.preprocessed_data;

    //Matrix2d a = test.y_train.inverse();
    //std::cout << a;

    return 0;
}