/*
This problem was asked by Airbnb.

Given a list of integers, write a function that returns the largest sum of non-adjacent numbers. 
Numbers can be 0 or negative.

For example, [2, 4, 6, 2, 5] should return 13, since we pick 2, 6, and 5. 
[5, 1, 1, 5] should return 10, since we pick 5 and 5.

Follow-up: Can you do this in O(N) time and constant space?
*/


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll maxSum(std::vector<int> v) {
    ll prev = 0, maxVal = 0;
    for (auto& val: v) {
        ll temp = maxVal;
        maxVal = max(maxVal, prev + val);
        prev = temp;
    }
    
    return maxVal;
}

int main() {
    
    std::vector<int> v = {2, 4, 6, 2, 5};
    std::vector<int> v2 = {5, 1, 1, 5};
    
    std::cout << maxSum(v) << std::endl;
    std::cout << maxSum(v2) << std::endl;
    
    return 0;
}
