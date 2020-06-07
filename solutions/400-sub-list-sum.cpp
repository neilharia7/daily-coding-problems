/*
This problem was asked by Goldman Sachs.

Given a list of numbers L, 
*implement a method sum(i, j) which returns the sum from the sublist L[i:j] (including i, excluding j).

For example, given L = [1, 2, 3, 4, 5], sum(1, 3) should return sum([2, 3]), which is 5.

You can assume that you can do some pre-processing. sum() should be optimized over the pre-processing step.
*/

#include<bits/stdc++.h>
using namespace std;

int subListSum(std::vector<int>& v, int i, int j) {
    
    int total = 0;
    while (i < j) {
        total += v[i];
        i++;
    }
    return total;
}

int main() {
    std::vector<int> v = {1, 2, 3, 4, 5};
    
    int i = 1, j = 3;
    std::cout << subListSum(v, i, j) << std::endl;
    return 0;
}
