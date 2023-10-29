#include <iostream>
#include "parse_health_data.h"
#include "parse_data.h"

int main() {

  std::cout << "Sup bro" <<  std::endl;

  ParseHealthData health_data_parser;

  ParseData::Data health_data = health_data_parser.parse_input_file("data/raw_data/health_data.txt");

  return 0;
}