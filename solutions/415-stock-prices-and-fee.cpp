/*
This problem was asked by Affirm.

Given a array of numbers representing the stock prices of a company in chronological order,
write a function that calculates the maximum profit you could have made from buying and selling that stock.
You're also given a number fee that represents a transaction fee for each buy and sell transaction.

You must buy before you can sell the stock, but you can make as many transactions as you like.

For example, given [1, 3, 2, 8, 4, 10] and fee = 2, you should return 9, 
since you could buy the stock at 1 dollar, and sell at 8 dollars, 
and then buy it at 4 dollars and sell it at 10 dollars. 
Since we did two transactions, there is a 4 dollar fee, so we have 7 + 6 = 13 profit minus 4 dollars of fees.
*/

#include<bits/stdc++.h>
using namespace std;


int profitFromStocks(vector<int>& v, int fee) {
    
    if (v.size() < 2)
        return 0;
    
    int totalProfit = 0;
    int buyPrice = -INT_MAX;
    for (int i = 0; i < v.size() - 1; ++i) {
        if ((v[i] + fee) <= v[i + 1] && buyPrice == -INT_MAX) {
            buyPrice = v[i] + fee;
        }
        
        if (v[i] > v[i + 1] && buyPrice != -INT_MAX && buyPrice < v[i]) {
            totalProfit += v[i] - buyPrice;
            buyPrice = -INT_MAX;
        }
    }
    
    if (buyPrice != -INT_MAX) {
        totalProfit += (v[v.size() - 1] - buyPrice);
    }
    return totalProfit;
}


int main() {
    
    std::vector<int> v = {1, 3, 2, 8, 4, 10};
    int fee = 2;
    
    std::cout << profitFromStocks(v, fee) << std::endl;
    return 0;
}
