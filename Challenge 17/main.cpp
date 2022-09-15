// Section 19
// Challenge 4
// Copy Romeo and Juliet with line numbers
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


int main() {

    // Create an input file stream
    ifstream in_file;
    in_file.open("romeoandjuliet.txt");
    if (!in_file) {
        cerr << "Problem opening file" << endl;
        return 1;
    }

    // concatenate the line number to the line
    string line;
    int line_number {1};
    vector<string> new_lines;
    while (getline(in_file, line)) {
        new_lines.push_back(to_string(line_number) +  ": " + line);
        line_number++;
    }

    // save new lines to a new file
    ofstream out_file;
    out_file.open("romeoandjuliet_with_line_numbers.txt");
    if (!out_file) {
        cerr << "Problem creating new file" << endl;
        return 1;
    }
    for (auto line : new_lines) {
        out_file << line << endl;
    }
    cout << "File written to romeoandjuliet_with_line_numbers.txt" << endl;

    in_file.close();
    return 0;
}

