#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Function to set the terminal color
void setColor(const string& colorCode) {
    cout << "\033[" << colorCode << "m";
}

// Function to reset the terminal color to normal
void resetColor() {
    cout << "\033[0m";
}

// Function to find the LCS table
vector<vector<int>> LCS(const string& s1, const string& s2) {
    int m = s1.size(), n = s2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp;
}

// Function to display differences using LCS
void diff(const string& s1, const string& s2) {
    vector<vector<int>> dp = LCS(s1, s2);

    int i = s1.size(), j = s2.size();
    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            cout << s1[i - 1];
            i--; j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            setColor("31"); // Red for deletion
            cout << s1[i - 1];
            resetColor();
            i--;
        } else {
            setColor("32"); // Green for addition
            cout << s2[j - 1];
            resetColor();
            j--;
        }
    }

    while (i > 0) {
        setColor("31"); // Red for deletion
        cout << s1[i - 1];
        resetColor();
        i--;
    }

    while (j > 0) {
        setColor("32"); // Green for addition
        cout << s2[j - 1];
        resetColor();
        j--;
    }
}

int main() {
    string s1 = "ACCGGTCGAGTGCGCGGAAGCCGGCCGAA";
    string s2 = "GTCGTTCGGAATGCCGTTGCTCTGTAA";

    diff(s1, s2);

    return 0;
}
