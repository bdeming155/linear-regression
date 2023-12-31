/// @file
#ifndef SVM_LINEAR_REGRESSION_H
#define SVM_LINEAR_REGRESSION_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <Eigen/Dense>

using namespace Eigen;

/**
  * Base class for linear regression models. Includes methods to preprocess data,
  * fit a model, and make predictions.
 */
class Regression{

public:

  // Model coefficients for the regression model
  ArrayXXd beta;

  /**
   * Fit a regression model to the input training data.
   */
  virtual void fit_model(ArrayXXd X, ArrayXXd y_train_input, bool standardize_data_flag_input) = 0;

  /**
   * Make a prediction on input variable given the model fit to the training data.
   */
  float predict(MatrixXd x_test){
    std::cout << beta.matrix() << std::endl;
    MatrixXd prediction = x_test * beta.matrix();

    return prediction(0);
  }

};


/**
   * Simple linear regression implementation.
 */
class LinearRegression : public Regression{

public:

  void fit_model(ArrayXXd X_train, ArrayXXd y_train, bool standardize_data_flag = true) {

    beta =
             (X_train.matrix().transpose() * X_train.matrix())
                 .inverse() *
        X_train.matrix().transpose() * y_train.matrix();
       }
};


/**
   * Ridge regression implementation.
 */
class RidgeRegression : public Regression{

public:
  float lambda_ridge;

  RidgeRegression(float lambda_ridge_input = 10){

    // Lambda controls the amount of shrinkage of the ridge regression coefficients
    lambda_ridge = lambda_ridge_input;

  }

  void fit_model(ArrayXXd X_train, ArrayXXd y_train, bool standardize_data_flag = true) {

    ArrayXXd X_train_intercept = ArrayXXd::Ones(X_train.rows(),X_train.cols()+1);

//    if (standardize_data_flag) {
//      X_train = standardize_data(X_train);
//    }
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
