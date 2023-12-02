#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <Eigen/Dense>

using namespace Eigen;


/**
  * Parses health health_data_ex txt files with the following health_data_ex headers: id, lcavol,
  * lweight, age, lbph, svi, lcp, gleason, pgg45, lpsa, train. Loads the health_data_ex
  * into the HealthData container where each health_data_ex category is stored as an
  * attribute.
 */
class ParseHealthData {
public:

  /**
  * Stores health health_data_ex which is loaded from the txt file.
  */
  struct HealthData{
        std::vector<int> id;
        std::vector<float> lcavol;
        std::vector<float> lweight;
        std::vector<int> age;
        std::vector<float> lbph;
        std::vector<float> svi;
        std::vector<float> lcp;
        std::vector<float> gleason;
        std::vector<float> pgg45;
        std::vector<float> lpsa;
        std::vector<std::string> train;

        ArrayXXd X_train;
        ArrayXXd y_train;
  };

  /**
  * Reads a txt file and saves the health_data_ex into a HealthData container.
  *
  * @param input_filepath Path to the health_data_ex file
  * @return The parsed health_data_ex
   */
  HealthData parse_input_file(std::string input_file_path) {
    // Create a text string, which is used to output the text file
    std::string line_data;
    HealthData output_data;

    int line_num = 0;

    // Read from the text file
    std::ifstream input_file(input_file_path);

    // Use a while loop together with the getline() function to read the file line by line
    while (getline(input_file, line_data)) {

      std::stringstream line(line_data);
      int col_num = 0;

      // Start saving the health_data_ex after the first (header) line
      if (line_num > 0) {
        while (line.good()) {
          std::string substr;
          std::getline(line, substr, ',');
          switch (col_num) {
          case 0:
            output_data.id.push_back(std::stoi(substr));
            break;
          case 1:
            output_data.lcavol.push_back(std::stof(substr));
            break;
          case 2:
            output_data.lweight.push_back(std::stof(substr));
            break;
          case 3:
            output_data.age.push_back(std::stof(substr));
            break;
          case 4:
            output_data.lbph.push_back(std::stof(substr));
            break;
          case 5:
            output_data.svi.push_back(std::stof(substr));
            break;
          case 6:
            output_data.lcp.push_back(std::stof(substr));
            break;
          case 7:
            output_data.gleason.push_back(std::stof(substr));
            break;
          case 8:
            output_data.pgg45.push_back(std::stof(substr));
            break;
          case 9:
            output_data.lpsa.push_back(std::stof(substr));
            break;
          case 10:
            output_data.train.push_back(substr);
            break;
          }
          col_num += 1;
        }
      }
      line_num += 1;
    }

    // Close the file
    input_file.close();

    int num_rows = output_data.id.size();
    // UPDATE THIS
    int num_cols = 8;

    ArrayXXd X(num_rows, num_cols);
    ArrayXXd y(num_rows, 1);
    output_data.X_train = X;
    output_data.y_train = y;

    for (int row = 0; row < num_rows; row++) {
      output_data.X_train(row,0) = output_data.lcavol[row];
      output_data.X_train(row,1) = output_data.lweight[row];
      output_data.X_train(row,2) = output_data.age[row];
      output_data.X_train(row,3) = output_data.lbph[row];
      output_data.X_train(row,4) = output_data.svi[row];
      output_data.X_train(row,5) = output_data.lcp[row];
      output_data.X_train(row,6) = output_data.gleason[row];
      output_data.X_train(row,7) = output_data.pgg45[row];
      output_data.y_train(row,0) = output_data.lpsa[row];

    }

    return output_data;
  }

};