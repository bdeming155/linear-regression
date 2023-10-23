
/// @file
#include <iostream>
#include "parse_data.h"

int main() {

  std::cout << "Sup bro" <<  std::endl;

  ParseData parser;

  parser.parse_input_file("hey.json");

  return 0;
}