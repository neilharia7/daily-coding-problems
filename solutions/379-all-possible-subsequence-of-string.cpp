/*
This problem was asked by Microsoft.

Given a string, generate all possible subsequences of the string.

For example, given the string xyz, return an array or set with the following strings:


x
y
z
xy
xz
yz
xyz
Note that zx is not a valid subsequence since it is not in the order of the given string.
*/


#include<bits/stdc++.h>
using namespace std;

std::vector<string> subsequence;

void generateSubsequence(string input, string output) {
    if (input.length() == 0) {
        subsequence.push_back(output);
        return;
    }
    generateSubsequence(input.substr(1), output);
    generateSubsequence(input.substr(1), output + input[0]);
}

int main() {
    generateSubsequence("xyz", "");
	
    for (auto& sub : subsequence)
        std::cout << sub << std::endl;
    return 0;
}
