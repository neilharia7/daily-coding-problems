/*

This problem was asked by Amazon.

Write a function that takes a natural number as input and returns the number of digits the input has.

Constraint: don't use any loops.
*/


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int numberCount(ll number) {
    if (number == 0)
        return 0;
        
    return 1 + numberCount(number / 10);
}

int main() {
    ll num = 1234567890;
    std::cout << numberCount(num) << std::endl;
}
