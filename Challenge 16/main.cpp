// Section 19
// Challenge 3
// Word counter
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

int main() {
    
    // open the file to search
    ifstream in_file;
    in_file.open("romeoandjuliet.txt");
    if (!in_file) {
        cerr << "Problem opening file" << endl;
        return 1;
    }

    // read the file into a vector of strings
    vector<string> words;
    string word;
    while (in_file >> word) {
        words.push_back(word);
    }
    in_file.close();
    
    // get the substring to search for
    string search;
    cout << "Enter the substring to search for: ";
    cin >> search;

    // search for the substring
    int count {};
    for (const auto &word: words) {
        if (word.find(search) != string::npos)
            count++;
    }

    // display the results
    cout << words.size() << " words were read from the file" << endl;
    cout << "The substring " << search << " was found " << count << " times" << endl;
    
    cout << endl;
    return 0;
}

