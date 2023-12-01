/// @file
#ifndef SVM_LINEAR_REGRESSION_H
#define SVM_LINEAR_REGRESSION_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <Eigen/Dense>

using namespace Eigen;

class RegressionBase{

private:


  ArrayXXd standardize_data(ArrayXXd input_data){
    int num_rows = static_cast<int>(input_data.rows());
    int num_cols = static_cast<int>(input_data.cols());
    ArrayXXd new_standardized_data(num_rows, num_cols);

    for (int i = 0; i < num_cols; i++) {

      double std_dev = std::sqrt(((input_data.col(i) - input_data.col(i).mean()).square()).sum()/(input_data.col(i).size()));

      new_standardized_data.col(i) = (input_data.col(i) - input_data.col(i).mean()) / std_dev;
    }


    return new_standardized_data;
  }
public:
  ArrayXXd preprocessed_data;
  ArrayXXd beta;
  ArrayXXd y_train;
  bool standardize_data_flag;

  void Regression(ArrayXXd X, ArrayXXd y_train_input, bool standardize_data_flag_input){

    y_train = y_train_input;
    standardize_data_flag = standardize_data_flag_input;
    preprocessed_data = ArrayXXd::Ones(X.rows(),X.cols()+1);

    ArrayXXd new_standardized_data = standardize_data(X);

    preprocessed_data << ArrayXXd::Ones(static_cast<int>(new_standardized_data.rows()), 1), new_standardized_data;

  }

  virtual void fit_model(){}

  float predict(MatrixXd x_test){

    MatrixXd prediction = x_test * beta.matrix();

    return prediction(0);
  }

};

class LinearRegression : public RegressionBase{

public:
  void fit_model() override{
         beta =
             (preprocessed_data.matrix().transpose() * preprocessed_data.matrix())
                 .inverse() *
             preprocessed_data.matrix().transpose() * y_train.matrix();
       }


};


//
//class Regression{
//private:
//
//  ArrayXXd standardize_data(ArrayXXd input_data){
//    int num_rows = static_cast<int>(input_data.rows());
//    int num_cols = static_cast<int>(input_data.cols());
//    ArrayXXd new_standardized_data(num_rows, num_cols);
//
//    for (int i = 0; i < num_cols; i++) {
//
//      double std_dev = std::sqrt(((input_data.col(i) - input_data.col(i).mean()).square()).sum()/(input_data.col(i).size()));
//
//      new_standardized_data.col(i) = (input_data.col(i) - input_data.col(i).mean()) / std_dev;
//    }
//
//
//    return new_standardized_data;
//  }
//
//public:
//    ArrayXXd preprocessed_data;
//    ArrayXXd beta;
//    ArrayXXd y_train;
//    bool standardize_data_flag;
//
//   Regression(ArrayXXd X, ArrayXXd y_train_input, bool standardize_data_flag_input){
//
//    y_train = y_train_input;
//    standardize_data_flag = standardize_data_flag_input;
//    preprocessed_data = ArrayXXd::Ones(X.rows(),X.cols()+1);
//
//    ArrayXXd new_standardized_data = standardize_data(X);
//
//    preprocessed_data << ArrayXXd::Ones(static_cast<int>(new_standardized_data.rows()), 1), new_standardized_data;
//
//   }
//
//   void fit_model() {
//     beta =
//         (preprocessed_data.matrix().transpose() * preprocessed_data.matrix())
//             .inverse() *
//         preprocessed_data.matrix().transpose() * y_train.matrix();
//   }
//
//   float predict(MatrixXd x_test){
//
//     MatrixXd prediction = x_test * beta.matrix();
//
//     return prediction(0);
//
//   }
//
//};

#endif // SVM_LINEAR_REGRESSION_H
