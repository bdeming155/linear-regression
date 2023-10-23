
/// @file
#include <iostream>
#include "parse_data.h"

int main() {

  std::cout << "Sup bro" <<  std::endl;

  //parser.parse_input_file("hey.json");

  ParseHealthData health_data;
  health_data.parse_input_file("/Users/bdeming/Documents/regression_exercises/data/Prostate_Cancer.txt");
//  health_data.parse_input_file("hey.json");
//  health_data.read_csv();

  return 0;
}