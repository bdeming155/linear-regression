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
#ifndef SVM_READ_FILE_H
#define SVM_READ_FILE_H
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void read_csv();

class ParseData {

public:
  void parse_input_file(std::string input_filename){

    std::string  file_prefix = input_filename.substr(input_filename.find_last_of(".") + 1);

    if(file_prefix == "json"){
      std::cout << "JSON file" << std::endl;
    } else if(file_prefix ==  "txt"){
      std::cout << "TXT file" << std::endl;
    } else if(file_prefix ==  "csv"){
      std::cout << "CSV file" << std::endl;
    } else{
      std::cout << "Could not identify file type!" << std::endl;
    }
  };

private:
  void read_csv() {

    // File pointer
    fstream fin;

    string input_file;
    cout << "Enter input file path "; // Type a number and press enter
    cin >> input_file;                // Get user input from the keyboard

    // Open an existing file
    fin.open(input_file, ios::in);

    // Read the Data from the file
    // as String Vector
    string line, temp;

    // Loop through each row
    while (fin >> temp) {

      // read an entire row and
      // store it in a string variable 'line'
      getline(fin, line);

      // used for breaking words
      stringstream s(line);

      // Loop through each element of the line
      while (s.good()) {
        string element;
        getline(s, element, ',');
        cout << element << endl;
      }
    }
  }

};

#endif // SVM_READ_FILE_H