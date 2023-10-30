#include <iostream>
#include "parse_health_data.h"

int main() {

  ParseHealthData health_data_parser;

  ParseHealthData::HealthData health_data = health_data_parser.parse_input_file("data/raw_data/health_data.txt");

  for (auto val :  health_data.gleason){
    std::cout << val << "\n";}

  return 0;
}