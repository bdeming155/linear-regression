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

};parse_data.h
