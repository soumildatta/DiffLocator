// Author: Soumil Datta

#include <iostream>
using std::cout;
using std::endl;

#include <fstream>
using std::ifstream;

int main(int argc, char *argv[]) {
    char *filename1 = argv[1];
    char *filename2 = argv[2];

    // Read from a file:
    ifstream infile1(filename1);

    char c;
    while (infile1.get(c)) {
        cout << c;
    }

    // Read from second file 
    ifstream infile2(filename2);

    while (infile2.get(c)) {
        cout << c;
    }

    // close the ifstreams
    infile1.close();
    infile2.close();

    return 0;
}