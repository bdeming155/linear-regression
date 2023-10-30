#include <iostream>
#include "parse_health_data.h"

int main() {

  ParseHealthData health_data_parser;

  std::cout << "Enter path to data file: \n";
  std::string input_file;
  std::cin >> input_file;

  ParseHealthData::HealthData health_data = health_data_parser.parse_input_file(input_file);

  for (auto val :  health_data.id){
    std::cout << val << "\n";}

  return 0;
}