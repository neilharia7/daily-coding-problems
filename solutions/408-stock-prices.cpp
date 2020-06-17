/*
This problem was asked by Facebook.

Given an array of numbers representing the stock prices of a company in chronological order and an integer k,
return the maximum profit you can make from k buys and sells. 
You must buy the stock before you can sell it, and you must sell the stock before you can buy it again.

For example, given k = 2 and the array [5, 2, 4, 0, 1], you should return 3.
*/


#include <bits/stdc++.h>
using namespace std;


int maxValue(std::vector<int>& v, int k) {
    int revenue = 0, buy = -INT_MAX;
    std::vector<int> profit;
    
    for (int i = 0; i < v.size() - 1; ++i) {
        if (v[i] < v[i + 1] && buy == -INT_MAX) {
            buy = v[i];
        }
        if (v[i] > v[i + 1] && buy != -INT_MAX) {
            profit.push_back(v[i] - buy);
            buy = -INT_MAX;
        }
    }
    if (buy != -INT_MAX) {
        profit.push_back(v[v.size() - 1] - buy);
    }
    
    sort(profit.begin(), profit.end(), std::greater<>());
    
    for (int i = 0; i < k; ++i) {
        revenue += profit[i];
    }
    
    return revenue;
}



int main() {
	std::vector<int> v = {5, 2, 4, 0, 1};
	int k = 2;
	
	std::cout << maxValue(v, k) << std::endl;
	
	return 0;
}
