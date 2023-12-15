/// @file
#ifndef SVM_LINEAR_REGRESSION_H
#define SVM_LINEAR_REGRESSION_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <Eigen/Dense>

using namespace Eigen;

class Regression{

public:

  ArrayXXd beta;

  ArrayXXd standardize_data(ArrayXXd input_data){
    int num_rows = static_cast<int>(input_data.rows());
    int num_cols = static_cast<int>(input_data.cols());
    ArrayXXd standardized_data(num_rows, num_cols);

    for (int i = 0; i < num_cols; i++) {

      double std_dev = std::sqrt(((input_data.col(i) - input_data.col(i).mean()).square()).sum()/(input_data.col(i).size()));

      standardized_data.col(i) = (input_data.col(i) - input_data.col(i).mean()) / std_dev;
    }

    return standardized_data;
  }

  virtual void fit_model(ArrayXXd X, ArrayXXd y_train_input, bool standardize_data_flag_input) = 0;

  float predict(MatrixXd x_test){

    MatrixXd prediction = x_test * beta.matrix();

    return prediction(0);
  }

};

class LinearRegression : public Regression{

public:

  void fit_model(ArrayXXd X_train, ArrayXXd y_train, bool standardize_data_flag = true) {

    ArrayXXd X_train_intercept = ArrayXXd::Ones(X_train.rows(),X_train.cols()+1);

    if (standardize_data_flag) {
      X_train = standardize_data(X_train);
    }
    X_train_intercept << ArrayXXd::Ones(static_cast<int>(X_train.rows()), 1), X_train;

    beta =
             (X_train_intercept.matrix().transpose() * X_train_intercept.matrix())
                 .inverse() *
        X_train_intercept.matrix().transpose() * y_train.matrix();
       }

};


class RidgeRegression : public Regression{

public:
  float lambda_ridge;

  RidgeRegression(float lambda_ridge_input){

    lambda_ridge = lambda_ridge_input;

  }

  void fit_model(ArrayXXd X_train, ArrayXXd y_train, bool standardize_data_flag = true) {

    ArrayXXd X_train_intercept = ArrayXXd::Ones(X_train.rows(),X_train.cols()+1);

    if (standardize_data_flag) {
      X_train = standardize_data(X_train);
    }
    X_train_intercept << ArrayXXd::Ones(static_cast<int>(X_train.rows()), 1), X_train;

    MatrixXd A = lambda_ridge * MatrixXd::Identity(static_cast<int>(X_train_intercept.cols()),static_cast<int>(X_train_intercept.cols()));

    A(0,0) = 0;

    beta =
        (X_train_intercept.matrix().transpose() * X_train_intercept.matrix() + A)
            .inverse() *
        X_train_intercept.matrix().transpose() * y_train.matrix();
  }

};

#endif // SVM_LINEAR_REGRESSION_H
