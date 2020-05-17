/*
This problem was asked by Jane Street.

cons(a, b) constructs a pair, and car(pair) and cdr(pair) returns the first and last element of that pair. 
For example, car(cons(3, 4)) returns 3, and cdr(cons(3, 4)) returns 4.

Given this implementation of cons:

def cons(a, b):
    def pair(f):
        return f(a, b)
    return pair
Implement car and cdr.
*/


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct constructPair {
    int a, b;
};

constructPair cons(int i, int j) {
    constructPair p;
    p.a = i;
    p.b = j;
    return p;
}

int car(constructPair p) {
    return p.a;
}

int cdr(constructPair p) {
    return p.b;
}

int main() {
    std::cout << car(cons(3, 4)) << std::endl;
    std::cout << cdr(cons(3, 4)) << std::endl;
    
    return 0;
}
