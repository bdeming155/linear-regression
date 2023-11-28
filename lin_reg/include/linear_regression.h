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
private:


  ArrayXXd standardize_data(ArrayXXd input_data){
    int num_rows = static_cast<int>(input_data.rows());
    int num_cols = static_cast<int>(input_data.cols());
    ArrayXXd new_standardized_data(num_rows, num_cols);

    for (int i = 0; i < num_cols; i++) {

      double std_dev = std::sqrt((input_data.col(i) - input_data.col(i).mean()).square().sum()/(input_data.col(i).size()-1));

//      std:: cout << (input_data.col(i)) <<std::endl<<std::endl;
//      std:: cout << (input_data.col(i).mean()) <<std::endl<<std::endl;
//      std:: cout << (input_data.col(i) - input_data.col(i).mean()) << std::endl << std::endl;

      new_standardized_data.col(i) = (input_data.col(i) - input_data.col(i).mean()) / std_dev;
    }


    return new_standardized_data;
  }

public:
    ArrayXXd preprocessed_data;
    ArrayXXd beta;
    ArrayXXd y_train;
    bool standardize_data_flag;

   Regression(ArrayXXd X, ArrayXXd y_train_input, bool standardize_data_flag_input){

    y_train = y_train_input;
    standardize_data_flag = standardize_data_flag_input;
    preprocessed_data = ArrayXXd::Ones(X.rows(),X.cols()+1);

    ArrayXXd new_standardized_data = standardize_data(X);

    preprocessed_data << ArrayXXd::Ones(static_cast<int>(new_standardized_data.rows()), 1), new_standardized_data;

    fit_model();

    float prediction = predict();

//    MatrixXd prediction = x_test * beta.matrix();
    std::cout << prediction;

   }

   void fit_model() {
     beta =
         (preprocessed_data.matrix().transpose() * preprocessed_data.matrix())
             .inverse() *
         preprocessed_data.matrix().transpose() * y_train.matrix();
   }

   float predict(){

     MatrixXd x_test(1,3);
     x_test(0,0) = 1;
     x_test(0,1) = 3.2;
     x_test(0,2) = 4.5;

     MatrixXd prediction = x_test * beta.matrix();

     return prediction(0);

   }

};


#endif // SVM_LINEAR_REGRESSION_H
