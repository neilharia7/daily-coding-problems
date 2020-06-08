/*
This problem was asked by Twitter.

A permutation can be specified by an array P, where P[i] represents the location of the element at i in the permutation.
For example, [2, 1, 0] represents the permutation where elements at the index 0 and 2 are swapped.

Given an array and a permutation, apply the permutation to the array. 
For example, given the array ["a", "b", "c"] and the permutation [2, 1, 0], return ["c", "b", "a"].
*/

#include<bits/stdc++.h>
using namespace std;

vector<string> swapper(std::vector<string> s, std::vector<int> p) {
    
    for (int i = 0; i < s.size(); ++i) {
        if (i != p[i]) {
            swap(s[i], s[p[i]]);
            swap(i, p[i]);
        }
    }
    
    return s;
}

int main() {
    std::vector<string> str = {"a", "b", "c"};
    std::vector<int> permu = {2, 1, 0};
    
    std::vector<string> updated = swapper(str, permu);
    
    for (auto& i : updated) {
        std::cout << i << " ";
    }
    
    return 0;
}
