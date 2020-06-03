/*
This problem was asked by Google.

Given a string, return the length of the longest palindromic subsequence in the string.

For example, given the following string:

MAPTPTMTPA

Return 7, since the longest palindromic subsequence in the string is APTMTPA.
Recall that a subsequence of a string does not have to be contiguous!

Your algorithm should run in O(n^2) time and space.
*/


#include<bits/stdc++.h>
using namespace std;

int maxPalindromeSubsequence(string str) {
    
    int len = str.length();
    
    if (len < 2) {
        return len;
    }
    
    std::vector<vector <int>> v(len, vector<int> (len, 0));
    
    for (int i = 0; i < len; ++i) {
        v[i][i] = 1;
    }
    
    for (int i = 2; i <= len; ++i) {
        for (int j = 0; j < len - i + 1; ++j) {
            int k = i + j - 1;
            if (i == 2 && str.at(j) == str.at(k)) {
                v[j][k] = 2;
            } else if (str.at(j) == str.at(k)) {
                v[j][k] = v[j + 1][k - 1] + 2;   
            } else {
                v[j][k] = fmax(v[j + 1][k], v[j][k - 1]);
            }
        }
    }
    
    return v[0][len - 1];
}

int main() {
    string str = "MAPTPTMTPA";
    std::cout << maxPalindromeSubsequence(str) << std::endl;
    
    return 0;
}
