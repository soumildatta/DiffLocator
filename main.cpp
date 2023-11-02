// Author: Soumil Datta

#include <iostream>
using std::cout;
using std::endl;

#include <fstream>
using std::ifstream;

#include <sstream>
using std::istringstream;

#include <cstring>
using std::memset;

#include <string>
using std::string;

#include <stack>
using std::stack;

#include <algorithm>
using std::max;

#include <vector>
using std::vector;

#include "Colors.h"

// Function takes a list of lines from 2 files, returns the LCS lengths of the lines
vector<vector<int>> LCS(vector<string> lines1, vector<string> lines2) {
    int m = lines1.size();
    int n = lines2.size();

    // Create a 2D array with the lcs lengths of the lines
    // TODO: more efficient implementation
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (lines1[i-1] == lines2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp;
}

void diff(string s1, string s2) {
    // separate s1 into lines 
    istringstream iss1(s1), iss2(s2);

    string line;
    vector<string> lines1, lines2;

    while (getline(iss1, line)) {
        lines1.emplace_back(line);
    }

    while (getline(iss2, line)) {
        lines2.emplace_back(line);
    }

    // Find the LCS lengths of the lines
    vector<vector<int>> dp = LCS(lines1, lines2);

    // Find and display the differences
    stack<string> lineStack;
    Colors colors;

    int i = lines1.size(), j = lines2.size();
    while (i > 0 && j > 0) {
        // If the lines are the same, move on
        if (lines1[i-1] == lines2[j-1]) {
            --i;
            --j;
        } else if (dp[i-1][j] > dp[i][j-1]) { // If the line in file 1 is longer than the line in file 2
            lineStack.emplace("< " + lines1[i-1]);
            --i;
        } else { // If the line in file 2 is longer than the line in file 1
            lineStack.emplace("> " + lines2[j-1]);
            --j;
        }
    }

    // If there are any remaining lines in file 1, add them to the stack
    while (i > 0) {
        lineStack.emplace("< " + lines1[i-1]);
        --i;
    }

    // If there are any remaining lines in file 2, add them to the stack
    while (j > 0) {
        lineStack.emplace("> " + lines2[j-1]);
        --j;
    }

    // Print the stack
    while (!lineStack.empty()) {
        string currLine = lineStack.top();

        if(currLine[0] == '<') {
            colors.setRed();
        } else if (currLine[0] == '>') {
            colors.setGreen();
        }
        
        cout << currLine << endl;

        colors.setNormal();
        lineStack.pop();
    }
}


int main(int argc, char *argv[]) {
    // Check if the program has 2 filenames as input
    if (argc != 3) {
        cout << "Please enter 2 filenames as arguments" << endl;
        return 1;
    }

    Colors colors;
    char *filename1 = argv[1];
    char *filename2 = argv[2];

    // Read from a file:
    ifstream infile1(filename1);

    string s1, s2;

    char c;
    while (infile1.get(c)) {
        s1 += c;
    }

    // Read from second file 
    ifstream infile2(filename2);
    while (infile2.get(c)) {
        s2 += c;
    }

    // close the ifstreams
    infile1.close();
    infile2.close();

    // colors.setGreen();
    // std::cout << "This is green text!" << std::endl;
    // colors.setNormal();
    // std::cout << "This is normal white text!" << std::endl;

    // string s1 = "AGGTAB";
    // string s2 = "GXTXAYB";

    diff(s1, s2);

    return 0;
}