/*
This problem was asked by Facebook.

Given the mapping a = 1, b = 2, ... z = 26, and an encoded message, count the number of ways it can be decoded.

For example, the message '111' would give 3, since it could be decoded as 'aaa', 'ka', and 'ak'.

You can assume that the messages are decodable. For example, '001' is not allowed.
*/

#include<bits/stdc++.h>
using namespace std;

int decodeWays(string str) {
    if (str.length() == 1) 
        return 1;
    
    if (str.length() == 2)
        return stoi(str) > 26 ? 1 : 2;
    
    if (stoi(str.substr(0, 2)) > 26)
        return decodeWays(str.substr(1));
    
    return decodeWays(str.substr(1)) + decodeWays(str.substr(2));
}

int main() {
    std::vector<string> v = {"11111", "12346789", "987654321", "112233"};
    
    for (auto str : v) {
        std::cout << decodeWays(str) << std::endl;
    }
    
    return 0;
}
