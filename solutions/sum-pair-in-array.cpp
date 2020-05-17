/*
Given a list of numbers and a number k, return whether any two numbers from the list add up to k.
For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.
Bonus: Can you do this in one pass?
*/


#include <bits/stdc++.h>
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
    int n = readInt(), k = readInt(), temp;
    std::vector<int> v(n);
    unordered_set<int> s;

    for (int i = 0; i < v.size(); ++i) {
        temp = readInt();
        if (!s.count(k - temp)) {
            s.insert(temp);
        } else {
            std::cout << "true" << std::endl;
            return 1;
        }
    }
    std::cout << "false" << std::endl;
    return 0;
}
