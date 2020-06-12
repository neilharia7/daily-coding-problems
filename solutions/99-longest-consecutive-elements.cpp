/*
This problem was asked by Microsoft.

Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example, given [100, 4, 200, 1, 3, 2], the longest consecutive element sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.
*/


#include<bits/stdc++.h>
using namespace std;


int longestSubsequence(std::vector<int>& v) {
    
    if (v.size() == 0)
        return 0;
    
    unordered_set<int> s;
    int max_len = 0;
    for (auto& i : v) {
        s.insert(i);
    }
    
    for (int i = 0; i < v.size(); ++i) {
        if (s.count(v[i] - 1) == 0) {
            int j = v[i];
            while (s.count(j) == 1) {
                ++j;
            }
            max_len = max(max_len, j - v[i]);
        }   
    }
    return max_len;
}


int main() {
    std::vector<int> v = {100, 4, 200, 1, 2, 3};
    std::cout << longestSubsequence(v) << std::endl;
    return 0;
}
