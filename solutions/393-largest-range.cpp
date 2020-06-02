/*
This problem was asked by Airbnb.

Given an array of integers, return the largest range, inclusive, of integers that are all included in the array.

For example, given the array [9, 6, 1, 3, 8, 10, 12, 11], return (8, 12) since 8, 9, 10, 11, and 12 are all in the array.
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    std::vector<int> v = {9, 6, 1, 3, 8, 10, 12, 11};
    int temp = (v.size() / 2) + 1;
    
    sort(v.begin(), v.end());
    std::cout << v[v.size() - temp] << ", " << v[v.size() - 1] << std::endl;
    return 0;
}
