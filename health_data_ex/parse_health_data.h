#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <Eigen/Dense>
#include <Eigen/Core>

using namespace Eigen;


/**
  * Parses health health_data_ex txt files with the following health_data_ex headers: id, lcavol,
  * lweight, age, lbph, svi, lcp, gleason, pgg45, lpsa, train. Loads the health_data_ex
  * into the HealthData container where each health_data_ex category is stored as an
  * attribute.
 */
class ParseHealthData {
public:

  ParseHealthData(std::string input_file_path){

    parse_input_file(input_file_path);

    get_lin_reg_mats();

  }

int NUM_INPUT_VARS = 8;

  struct LinRegMats {
    MatrixXd X;
    MatrixXd y;
  };

  LinRegMats lin_reg_mats;


  /**
  * Stores health health_data_ex which is loaded from the txt file.
  */
  struct HealthData{
        // Sample ID
        std::vector<int> id;

        // Output variable
        std::vector<double> lcavol;

        // Input variables
        std::vector<double> lweight;
        std::vector<double> age;
        std::vector<double> lbph;
        std::vector<double> svi;
        std::vector<double> lcp;
        std::vector<double> gleason;
        std::vector<double> pgg45;
        std::vector<double> lpsa;
        std::vector<std::string> train;

  };

  HealthData parsed_data;


  /**
  * Reads a txt file and saves the health_data_ex into a HealthData container.
  *
  * @param input_filepath Path to the health_data_ex file
  * @return The parsed health_data_ex
   */
  void parse_input_file(std::string input_file_path) {
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
            parsed_data.id.push_back(std::stoi(substr));
            break;
          case 1:
            parsed_data.lcavol.push_back(std::stof(substr));
            break;
          case 2:
            parsed_data.lweight.push_back(std::stof(substr));
            break;
          case 3:
            parsed_data.age.push_back(std::stof(substr));
            break;
          case 4:
            parsed_data.lbph.push_back(std::stof(substr));
            break;
          case 5:
            parsed_data.svi.push_back(std::stof(substr));
            break;
          case 6:
            parsed_data.lcp.push_back(std::stof(substr));
            break;
          case 7:
            parsed_data.gleason.push_back(std::stof(substr));
            break;
          case 8:
            parsed_data.pgg45.push_back(std::stof(substr));
            break;
          case 9:
            parsed_data.lpsa.push_back(std::stof(substr));
            break;
          case 10:
            parsed_data.train.push_back(substr);
            break;
          }
          col_num += 1;
        }
      }
      line_num += 1;
    }

    // Close the file
    input_file.close();
    
  }

  void get_lin_reg_mats(){
    int num_rows = parsed_data.id.size();
    int num_cols = NUM_INPUT_VARS+1;

    MatrixXd X(num_rows, num_cols);
    MatrixXd y(num_rows,1);

    // https://stackoverflow.com/questions/17036818/initialise-eigenvector-with-stdvector
    X.col(0) = VectorXd::Ones(num_rows);
    X.col(1) = standardize_data(Eigen::Map<Eigen::VectorXd, Eigen::Unaligned>(parsed_data.lcavol.data(), num_rows));
    X.col(2) = standardize_data(Eigen::Map<Eigen::VectorXd, Eigen::Unaligned>(parsed_data.lweight.data(), num_rows));
    X.col(3) = standardize_data(Eigen::Map<Eigen::VectorXd, Eigen::Unaligned>(parsed_data.age.data(), num_rows));
    X.col(4) = standardize_data(Eigen::Map<Eigen::VectorXd, Eigen::Unaligned>(parsed_data.lbph.data(), num_rows));
    X.col(5) = standardize_data(Eigen::Map<Eigen::VectorXd, Eigen::Unaligned>(parsed_data.svi.data(), num_rows));
    X.col(6) = standardize_data(Eigen::Map<Eigen::VectorXd, Eigen::Unaligned>(parsed_data.lcp.data(), num_rows));
    X.col(7) = standardize_data(Eigen::Map<Eigen::VectorXd, Eigen::Unaligned>(parsed_data.gleason.data(), num_rows));
    X.col(8) = standardize_data(Eigen::Map<Eigen::VectorXd, Eigen::Unaligned>(parsed_data.pgg45.data(), num_rows));

    y = Eigen::Map<Eigen::VectorXd, Eigen::Unaligned>(parsed_data.lpsa.data(), num_rows);

    lin_reg_mats.X = X;
    lin_reg_mats.y = y;

  }

  /**
   * Pre-process the data by standardizing the mean and standard deviation.
   */
  VectorXd standardize_data(VectorXd input_data){

    ArrayXd input_array(input_data);

    ArrayXd standardized_data(input_data.size());

    double std_dev = std::sqrt(((input_array - input_array.mean()).square()).sum()/(input_array.size()));

    standardized_data = (input_array - input_array.mean()) / std_dev;

    return VectorXd(standardized_data);
  }

};