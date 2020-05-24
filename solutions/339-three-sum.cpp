/*
Given an array of numbers and a number k, 
determine if there are three entries in the array which add up to the specified number k. 
For example, given [20, 303, 3, 4, 25] and k = 49, return true as 20 + 4 + 25 = 49.
*/


#include<bits/stdc++.h>
using namespace std;

bool threeSum(std::vector<int> v, int value) {
    for (int i = 0; i < v.size() - 2; ++i) {
        int current = value - v[i];
        
        unordered_set<int> s;
        for (int j = i + 1; j < v.size(); ++j) {
            if (s.count(current - v[j])) {
                return true;
            }
            s.insert(v[j]);
        }
    }
    return false;
}

int main() {
    std::vector<int> v = {20, 303, 3, 4, 25};
    int value = 49;
    
    std::cout << threeSum(v, value) << std::endl;
    return 0;
}
