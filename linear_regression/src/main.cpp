#include <iostream>
#include <Eigen/Dense>
#include "../include/linear_regression.h"
#include "../../health_data_ex/parse_health_data.h"


int main() {


  std::cout << "Enter path to health_data_ex file: \n";
  std::string input_file;
  std::cin >> input_file;

  ParseHealthData health_data_parser(input_file);


  LinearRegression test;
  test.fit_model(health_data_parser.lin_reg_mats.X, health_data_parser.lin_reg_mats.y);
  std::cout << test.beta << std::endl;
  // Test sample to run prediction on
  //float result;
//
//  Eigen::MatrixXd test_input_var(health_data.X_test.row(0));
//  result = test.predict(test_input_var);
//
//  std::cout << result << std::endl;

//  RidgeRegression test(10);
//    test.fit_model(health_data.X_train, health_data.y_train);
//    std::cout << test.beta;

  return 0;
}