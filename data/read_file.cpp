#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void read_csv() {

  // File pointer
  fstream fin;

  string input_file;
  cout << "Enter input file path "; // Type a number and press enter
  cin >> input_file; // Get user input from the keyboard

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
    while (s.good()){
      string element;
      getline(s, element, ',');
      cout << element << endl;

    }
  }
}



