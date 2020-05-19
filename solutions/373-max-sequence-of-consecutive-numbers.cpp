/*
This problem was asked by Facebook.

Given a list of integers L, 
find the maximum length of a sequence of consecutive numbers that can be formed using elements from L.

For example, given L = [5, 2, 99, 3, 4, 1, 100], return 5 as we can build a sequence [1, 2, 3, 4, 5] which has length 5.
*/

// O(nlog(n)) solution

#include<bits/stdc++.h>
using namespace std;

int longestConsecutiveSeries(vector<int> L) {
    sort(L.begin(), L.end());
    
    int longest = 0, count = 1;
    for (int i = 1; i < L.size(); ++i) {
        if (L[i] - L[i - 1] == 1) {
            count++;
        } else {
            count = 1;
        }
        
        if (longest < count) 
            longest = count;
    }
    return longest;
}

int main() {
    std::vector<int> L = {5, 2, 99, 3, 4, 1, 100};
    
    std::cout << longestConsecutiveSeries(L) << std::endl;
    return 0;
}

// O(n) solution

#include<bits/stdc++.h>
using namespace std;

int longestConsecutiveSeries(vector<int> L) {
    
    std::set<int> s;
    for(auto i : L)
        s.insert(i);
    
    std::vector<int> v(s.begin(), s.end());
    int longest = 0, count = 1;
    for (int i = 1; i < v.size(); ++i) {
        if (v[i] - v[i - 1] == 1) {
            count++;
        } else {
            count = 1;
        }
        
        if (longest < count) 
            longest = count;
    }
    return longest;
}

int main() {
    std::vector<int> L = {5, 2, 99, 3, 4, 1, 100};
    
    std::cout << longestConsecutiveSeries(L) << std::endl;
    return 0;
}
