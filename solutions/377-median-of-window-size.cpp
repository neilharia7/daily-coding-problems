/*
This problem was asked by Microsoft.

Given an array of numbers arr and a window of size k, 
print out the median of each window of size k starting from the left and moving right by one position each time.

For example, given the following array and k = 3:

[-1, 5, 13, 8, 2, 3, 3, 1]
Your function should print out the following:

5 <- median of [-1, 5, 13]
8 <- median of [5, 13, 8]
8 <- median of [13, 8, 2]
3 <- median of [8, 2, 3]
3 <- median of [2, 3, 3]
3 <- median of [3, 3, 1]

Recall that the median of an even-sized list is the average of the two middle numbers.
*/

#include<bits/stdc++.h>
using namespace std;

void getMedianWindow(vector<int> v, int window) {
    for (int i = 0; i <= v.size() - window; ++i) {
        
        std::vector<int> temp = {v.begin() + i, v.begin() + i + window};
        sort(temp.begin(), temp.end());
        
        if (window & 1 == 0) {
            std::cout << (temp[window / 2 - 1] + temp[window/2]) / 2 << std::endl;
        } else {
            std::cout << temp[window/2] << std::endl;
        }
    }
}

int main() {
    std::vector<int> v = {-1, 5, 13, 8, 2, 3, 3, 1};
    int window = 3;
    
    getMedianWindow(v, window);
    return 0;
}
