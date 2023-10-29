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

// Regular LCS
// int lcs(string s1, string s2) {
//     int m = s1.length();
//     int n = s2.length();

//     // Create a 2D array to store the lengths of the longest common subsequence
//     int dp[m+1][n+1];
//     memset(dp, 0, sizeof(dp));

//     for(int i = 1; i <= m; i++) {
//         for(int j = 1; j <= n; j++) {
//             // If the last characters of the strings match, then add 1 to the length of the LCS (diagonal element)
//             if(s1[i - 1] == s2[j - 1]) {
//                 dp[i][j] = dp[i - 1][j - 1] + 1;
//             }
//             // Else, take the max of the element above and the element to the left
//             else {
//                 dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//             }
//         }
//     }

//     return dp[m][n];
// }



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
    cout << s1 << endl << s2 << endl;
    cout << "Length of LCS is " << lcs(s1, s2) << endl;

    return 0;
}