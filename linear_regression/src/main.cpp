#include <iostream>
#include <Eigen/Dense>
#include "../include/linear_regression.h"
#include "../../health_data_ex/parse_health_data.h"


int main() {

  ParseHealthData health_data_parser;

  std::cout << "Enter path to health_data_ex file: \n";
  std::string input_file;
  std::cin >> input_file;

  ParseHealthData::HealthData health_data = health_data_parser.parse_input_file(input_file);

  LinearRegression test;
  test.fit_model(health_data.X_train, health_data.y_train);

  // Test sample to run prediction on
  Eigen::MatrixXd test_data{{1,1,1,1,1,1,1,1,1}};
  float result;
  result = test.predict(test_data);
  std::cout << result << std::endl;

//  RidgeRegression test(10);
//    test.fit_model(health_data.X_train, health_data.y_train);
//    std::cout << test.beta;

  return 0;
}