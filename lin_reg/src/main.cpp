#include <iostream>
#include <Eigen/Dense>
#include "../include/linear_regression.h"
#include "../../health_data_ex/parse_health_data.h"


ArrayXXd form_matrices(ParseHealthData::HealthData health_data){

  int num_rows = health_data.id.size();
  // UPDATE THIS
  int num_cols = 8;

  ArrayXXd X(num_rows, num_cols);
  ArrayXXd y(num_rows, 1);
  for (int row = 0; row < num_rows; row++) {
      X(row,0) = health_data.lcavol[row];
      X(row,1) = health_data.lweight[row];
      X(row,2) = health_data.age[row];
      X(row,3) = health_data.lbph[row];
      X(row,4) = health_data.svi[row];
      X(row,5) = health_data.lcp[row];
      X(row,6) = health_data.gleason[row];
      X(row,7) = health_data.pgg45[row];

      y(row,0) = health_data.lpsa[row];

    }


  return X, y;

}


int main() {

  ParseHealthData health_data_parser;

  std::cout << "Enter path to health_data_ex file: \n";
  std::string input_file;
  std::cin >> input_file;

  ParseHealthData::HealthData health_data = health_data_parser.parse_input_file(input_file);

  ArrayXXd X, y_train = form_matrices(health_data);
  std::cout << X1 << std::endl;

  ArrayXXd X(3,2);
  X(0,0) = 3.7;
  X(1,0) = 4.6;
  X(0,1) = 2.4;
  X(1,1) = 0.98;
  X(2,0) = 0.78;
  X(2,1) = 0.12;

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