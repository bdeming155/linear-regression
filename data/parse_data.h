// COPYRIGHTS AND PERMISSIONS:
// Copyright 2021 MORSE Corp All rights reserved.
//
// Subject to any rights the U.S. Government may have in the Software,
// permission is granted to the person rightfully obtaining a copy of this
// Software from MORSE Corp to use, copy, modify and distribute the
// Software only as expressly authorized in writing from MORSE Corp.
//
// The above copyright notice and this permission notice shall be included
// in all permitted copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
// OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
// IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
// CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
// TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
// SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
/// @file
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>


void read_csv();

class ParseData {
public:
  class Data{};
  void parse_input_file(std::string input_filename) {

    std::string file_prefix =
        input_filename.substr(input_filename.find_last_of(".") + 1);

    if (file_prefix == "json") {
      std::cout << "JSON file" ;
    } else if (file_prefix == "txt") {

      read_txt(input_filename);

    } else if (file_prefix == "csv") {
      std::cout << "CSV file"  ;
      read_csv(input_filename);


    } else {
      std::cout << "Could not identify file type!" ;
    }
  };
private:
  virtual Data read_csv(std::string input_file) = 0;
  virtual Data read_txt(std::string input_file) = 0;

};


class ParseHealthData : public ParseData{
  public:
    class HealthData : public ParseData::Data {
    public:
          std::vector<int> id;
          std::vector<float> lcavol;
          std::vector<float>  lweight;
          std::vector<int>  age;
          std::vector<float>  lbph;
          std::vector<float>  svi;
          std::vector<float>  lcp;
          std::vector<float>  gleason;
          std::vector<float>  pgg45;
          std::vector<float>  lpsa;
          std::vector<std::string>  train;
    };


    Data read_txt(std::string input_file){
      // Create a text string, which is used to output the text file
      std::string myText;
      HealthData output_data;
      int line_num = 0;

      // Read from the text file
      std::ifstream MyReadFile(input_file);

      // Use a while loop together with the getline() function to read the file line by line
      while (getline (MyReadFile, myText)) {

        std::stringstream line(myText);
        int line_ind = 0;

        if (line_num > 0){
        while (line.good()) {
          std::string substr;
          std::getline(line, substr, ',');
          switch(line_ind){
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
          //v.push_back(substr);
          line_ind += 1;
        }
      }
      line_num +=1;
      }

      for(std::string i : output_data.train)
        std::cout << i << "\n";

      // Close the file
      MyReadFile.close();

      return output_data;
    }

    Data read_csv(std::string input_file) {
      std::cout << input_file;

      // File pointer
      std::fstream fin;

//      std::cout << "Enter input file path "; // Type a number and press enter
//      std::cin >> input_file;                // Get user input from the keyboard

      // Open an existing file
      fin.open(input_file, std::ios::in);

      // Read the Data from the file
      // as String Vector
      std::string line, temp;

      // Loop through each row
      while (fin >> temp) {

        // read an entire row and
        // store it in a string variable 'line'
        getline(fin, line);

        // used for breaking words
        std::stringstream s(line);

        // Loop through each element of the line
        while (s.good()) {
          std::string element;
          getline(s, element, ',');
          std::cout << element;
        }
      }
    }

};
