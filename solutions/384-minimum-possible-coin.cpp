/*
This problem was asked by WeWork.

You are given an array of integers representing coin denominations and a total amount of money. 
Write a function to compute the fewest number of coins needed to make up that amount. 
If it is not possible to make that amount, return null.

For example, given an array of [1, 5, 10] and an amount 56, return 7 since we can use 5 dimes, 1 nickel, and 1 penny.

Given an array of [5, 8] and an amount 15, return 3 since we can use 5 5-cent coins.
*/

#include<bits/stdc++.h>
using namespace std;


int minimumPossibleCoin(vector<int> deno, int sum) {
    int len = deno.size();
    
    std::vector<int> dp(sum +1, INT_MAX);
    dp[0] = 0;
    
    for (int i = 1; i <= sum; i++) {
        for (int j = 0; j < len; j++) {
            if (deno[j] <= i) {
                int temp = dp[i - deno[j]];
                
                if (temp != INT_MAX && temp + 1 < dp[i])
                    dp[i] = temp + 1;
            }
        }
    }
    
    return dp[sum];
}

int main() {
    std::vector<int> v = {5, 8};
    int sum = 15;
    
    std::cout << minimumPossibleCoin(v, sum) << std::endl;
    return 0;
}
