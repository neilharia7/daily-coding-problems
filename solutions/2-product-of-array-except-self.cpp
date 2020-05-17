/*
This problem was asked by Uber.

Given an array of integers, return a new array such that each element at index i 
of the new array is the product of all the numbers in the original array except the one at i.

For example, if our input was [1, 2, 3, 4, 5], the expected output would be [120, 60, 40, 30, 24].
If our input was [3, 2, 1], the expected output would be [2, 3, 6].

Follow-up: what if you can't use division?
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int readInt() {
    bool minus = false;
    int result = 0;
    char ch;
    ch = getchar();
    while (true) {
        if (ch == '-')
            break;
        if (ch >= '0' && ch <= '9')
            break;
        ch = getchar();
    }
    if (ch == '-')
        minus = true;
    else
        result = ch - '0';
    while (true) {
        ch = getchar();
        if (ch < '0' || ch > '9')
            break;
        result = result * 10 + (ch - '0');
    }
    if (minus)
        return -result;
    else
        return result;
}

int main() {
    
    int n = readInt(), temp = 1;
    std::vector<int> v;
    std::vector<int> answers(n, 1);
    
    for (int i = 0; i < n; ++i) {
        v.push_back(readInt());
    }
    
    answers[0] = 1;
    for (int i = 1; i < n; ++i) {
        answers[i] = answers[i - 1] * v[i - 1];
    }
    
    for (int i = n - 2; i >= 0; --i) {
        temp *= v[i + 1];
        answers[i] *= temp;
    }
    
    for(int i = 0; i < n; ++i) {
        std::cout << answers[i] << " ";
    }
    return 0;
}
