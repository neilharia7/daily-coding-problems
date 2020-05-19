/*
This problem was asked by Stripe.

Given an array of integers, find the first missing positive integer in linear time and constant space.
In other words, find the lowest positive integer that does not exist in the array.
The array can contain duplicates and negative numbers as well.

For example, the input [3, 4, -1, 1] should give 2. The input [1, 2, 0] should give 3.

You can modify the input array in-place.
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> segregatePositives(vector<int> v) {
    int negIndex = 0;
    
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] <= 0) {
            swap(v[negIndex], v[i]);
            negIndex++;
        }
    }
    
    return vector<int>(v.begin() + negIndex, v.end());
}

int firstMissingPositive(vector<int> v) {
    int len = v.size();
    
    for (int i = 0; i < len; ++i) {
        int idx = abs(v[i]) - 1;
        std::cout << "index" << " " << idx << " " << v[i] << std::endl;
        
        if (idx < 1 && v[idx] > 0) {
            v[idx] *= -1;
        }
    }
    
    for(int i = 0; i < len; ++i)
        std::cout << v[i] << std::endl;
        
    for (int i = 0; i < len; ++i) {
        if (v[i] > 0)
            return i + 1;
    }
    
    return len + 1;   
}

int main() {
    std::vector<int> v = {3, 4, -2, -2, 1, 1, 0};
    // std::vector<int> v = {1, 2, 0};
    
    std::cout << firstMissingPositive(segregatePositives(v)) << std::endl;
    
    return 0;
}
