/*
This problem was asked by Two Sigma.

You are given an unsorted list of 999,000 unique integers, each from 1 and 1,000,000. 
Find the missing 1000 numbers. 
What is the computational and space complexity of your solution?
*/

// Worst

#include<bits/stdc++.h>
using namespace std;

int main() {
    int std::vector<int> v;
    
    // sample example
    for (int i = 1; i <= 999,000; ++i) {
        v.push_back(i);
    }
    
    int counter = 0;
    std::unordered_set<int> s(v.begin(); v.end());
    
    for (int i = 1; i <= 1000000; ++i) {
        if (counter < 1000)
            break;
        
        if (!v.count()) {
            ++counter;
            std::cout << i << std::endl;
        }
    }
    return 0;
}
