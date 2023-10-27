// Author: Soumil Datta

#include <iostream>
using std::cout;
using std::endl;

#include <fstream>
using std::ifstream;

int main(int argc, char *argv[]) {
    char *filename = argv[1];

    // Read from a file:
    ifstream infile(filename);

    char c;
    while (infile.get(c)) {
        cout << c;
    }

    return 0;
}