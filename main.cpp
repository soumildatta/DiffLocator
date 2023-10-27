// Author: Soumil Datta

#include <iostream>
using std::cout;
using std::endl;

#include <fstream>
using std::ifstream;

#include <cstring>
using std::memset;

#include <string>
using std::string;

#include <algorithm>
using std::max;

// Quick little struct to change console colors
// TODO: Abstract away into other file
struct Colors {
    inline void setRed() {
        cout << red;
    }

    inline void setGreen() {
        cout << green;
    }

    inline void setNormal() {
        cout << normal;
    }

private:
    const char *red = "\033[31m";
    const char *green = "\033[32m";
    const char *normal = "\033[0m";
};

int lcs(string s1, string s2) {
    int m = s1.length();
    int n = s2.length();
    int dp[m+1][n+1];

    memset(dp, 0, sizeof(dp));
    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {
            if(s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[m][n];
}

int main(int argc, char *argv[]) {
    Check if the program has 2 filenames as input
    if (argc != 3) {
        cout << "Please enter 2 filenames as arguments" << endl;
        return 1;
    }

    Colors colors;
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

    colors.setGreen();
    std::cout << "This is green text!" << std::endl;

    std::cout << "\033[0m";  // Reset the text color back to normal
    std::cout << "This is white text!" << std::endl;

    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";
    cout << "Length of LCS is " << lcs(s1, s2) << endl;

    return 0;
}