#include <iostream>
using std::cout;

#include <fstream>
using std::ifstream;

#include <string>
using std::string;

#include <sstream>
using std::stringstream;

#include <vector>
using std::vector;

#include <algorithm>
using std::max;

#include <stack>
using std::stack;

#include "Colors.h"
#include "timer.h"

string readFile(const string& filePath) {
    ifstream file(filePath);

    stringstream buffer;
    buffer << file.rdbuf();

    file.close();

    return buffer.str();
}

// Perform LCS on the two strings
vector<vector<int>> LCS(const string &s1, const string &s2) {
    auto m { s1.size() };
    auto n { s2.size() };

    // Create a 2D array with the lcs lengths of the lines
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp;
}

// Print the result from the 2D DP table
void printDiff(const string& s1, const string& s2, const vector<vector<int>>& dp) {
    auto i { s1.size() };
    auto j { s2.size() };

    // The output of diff is in reverse order since it traverses from the bottom right of the LCS array
    // So using a stack to reverse the output while printing
    stack<string> diffStack;

    // Traverse the table backwards
    while (i > 0 && j > 0) {
        // No difference so want to mark with ! so there is no coloring
        if (s1[i - 1] == s2[j - 1]) {
            diffStack.emplace("!" + string(1, s1[i - 1]));
            i--; j--;
        } 
        // There is a deletion from s1
        else if (dp[i - 1][j] > dp[i][j - 1]) {
            diffStack.emplace("-" + string(1, s1[i - 1]));
            i--;
        } 
        // There is an addition to s1
        else {
            diffStack.emplace("+" + string(1, s2[j - 1]));
            j--;
        }
    }

    // If there are any remaining characters in s1 or s2, add them to the stack
    while (i > 0) {
        diffStack.emplace("-" + string(1, s1[i - 1]));
        i--;
    }

    while (j > 0) {
        diffStack.emplace("+" + string(1, s2[j - 1]));
        j--;
    }

    Colors colors;
    string lcs_string = "";

    // Pop from stack and print
    while (!diffStack.empty()) {
        string currentChar = diffStack.top();

        if(string(1, currentChar[0]) == "+") {
            colors.setGreen();
            cout << currentChar[1];
        } else if(string(1, currentChar[0]) == "-") {
            colors.setRed();
            cout << currentChar[1];
        } else if(string(1, currentChar[0]) == "!") {
            colors.setNormal();
            cout << currentChar[1];
            lcs_string += currentChar[1];
        }

        diffStack.pop();
    }

    colors.setNormal();
    cout << "\n\n";

    // Print out the longest common string
    cout << "LCS: " << lcs_string << "\n";
    cout << "LCS Length: " << lcs_string.size() << "\n";
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cout << "Usage: " << argv[0] << " <file1> <file2>\n";
        return 1;
    }

    string s1 = readFile(argv[1]);
    string s2 = readFile(argv[2]);

    timer time;
    vector<vector<int>> dp = LCS(s1, s2);
    double LCSTime { time.getTime() };
    
    timer time2;
    printDiff(s1, s2, dp);
    double printTime { time2.getTime() };

    cout << "LCS Execution Time: " << LCSTime << " seconds\n";
    cout << "Print Execution Time: " << printTime << " seconds\n";

    return 0;
}
