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

    //beta = beta_input;
    y_train = y_train_input;
    standardize_data_flag = standardize_data_flag_input;
    preprocessed_data = ArrayXXd::Ones(X.rows(),X.cols()+1);

    ArrayXXd new_standardized_data = standardize_data(X);

    //std::cout << new_standardized_data;

    preprocessed_data << ArrayXXd::Ones(static_cast<int>(new_standardized_data.rows()), 1), new_standardized_data;

    // self.beta = np.linalg.inv(self.X_train_intercept.T @ self.X_train_intercept)
    // @ self.X_train_intercept.T @ self.y_train

    // FIT THE MODEL
    beta = (preprocessed_data.matrix().transpose() * preprocessed_data.matrix()).inverse() * preprocessed_data.matrix().transpose() * y_train.matrix();
    // PREDICT

    // HOW TO MATRIX MULTIPLY 1D MATRICES???

//    Matrix2d x_test(1,3);
//    x_test(0,0) = 1;
//    x_test(0,1) = 3.2;
//    x_test(0,2) = 4.5;
//    std::cout << x_test.matrix() << std::endl<< std::endl;
//    std::cout << beta.matrix() << std::endl<< std::endl;

    //Matrix2d prediction = x_test * beta.matrix();

   }




};


#endif // SVM_LINEAR_REGRESSION_H
