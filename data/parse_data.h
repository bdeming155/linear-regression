#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#pragma once

/**
 * Base class for data parser interface. Loads data from various types of files.
 *
 * @return The parsed data
 */
class ParseData {
public:

  /**
  * Container to store the parsed data.
  */
  class Data{};

  /**
  * Takes in the path to a data file and calls the corresponding read function
  * based on the file extension.
  *
  * @param input_filepath Path to the data file
  * @return The parsed data
  */
  Data parse_input_file(std::string input_filepath) {

    std::string file_prefix =
        input_filepath.substr(input_filepath.find_last_of(".") + 1);


    if (file_prefix == "txt") {

      Data output_data = read_txt(input_filepath);

      return output_data;

    } else if (file_prefix == "csv") {

      Data output_data = read_csv(input_filepath);

      return output_data;

    } else {
      std::cout << "Could not identify file type!" ;
      Data output_data;
      return output_data;
    }
  };

private:

  /**
  * Reads a csv file and returns the parsed data
  * @param input_filepath Path to the data file
  * @return The parsed data
  */
  virtual Data read_csv(std::string input_file) {
      Data output_data;
      return output_data;
  }

  /**
  * Reads a txt file and returns the parsed data
  *
  * @param input_filepath Path to the data file
  * @return The parsed data
  */
  virtual Data read_txt(std::string input_file) {
    Data output_data;
    return output_data;
  }
};

