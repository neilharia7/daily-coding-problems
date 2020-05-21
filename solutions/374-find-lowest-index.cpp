/*
This problem was asked by Amazon.

Given a sorted array arr of distinct integers, return the lowest index i for which arr[i] == i. 
Return null if there is no such index.

For example, given the array [-5, -3, 2, 3], return 2 since arr[2] == 2. 
Even though arr[3] == 3, we return 2 since it's the lowest index.
*/

#include<bits/stdc++.h>
using namespace std;

int getLowestIndex(vector<int>& v) {
    int low = 0, high = v.size();
    
    while (low <= high) {
        int mid = (low + high)/ 2;
        
        if (v[mid] == mid) {
            if (high - low == 0) {
                return mid;
            }
            high = mid;
        }
        else if (v[mid] < mid) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    std::vector<int> v = {-5, -3, 2, 3};
    std::cout << getLowestIndex(v) << std::endl;
}
