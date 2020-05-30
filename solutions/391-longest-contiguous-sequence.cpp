/*
This problem was asked by Facebook.

We have some historical clickstream data gathered from our site anonymously using cookies. 
The histories contain URLs that users have visited in chronological order.

Write a function that takes two users' browsing histories as input and 
returns the longest contiguous sequence of URLs that appear in both.

For example, given the following two users' histories:

user1 = ['/home', '/register', '/login', '/user', '/one', '/two']
user2 = ['/home', '/red', '/login', '/user', '/one', '/pink']

You should return the following:

['/login', '/user', '/one']
*/

#include<bits/stdc++.h>
using namespace std;

vector<string> longestContiguousSequence(std::vector<string> user1, std::vector<string> user2) {
    
    std::vector<string> res;
    int max_count = 0, idx = 0, count = 0;
    for (int i = 0; i < user1.size(); ++i) {
        for (int j = idx; j < user2.size(); ++j) {
            
            if (user1[i] == user2[j]) {
                ++count;
                ++idx;
                if (count > max_count) {
                    res = std::vector<string>(user1.begin() + i - max_count, user1.begin() + i + 1);
                    max_count = count;
                };
                i++;
            } else {
                count = 0;
            }
        }
    }
    return res;
}

int main() {
    std::vector<string> user1 = {"/home", "/register", "/login", "/user", "/one", "/two"};
    std::vector<string> user2 = {"/home", "/red", "/login", "/user", "/one", "/pink"};
    
    std::vector<string> res = longestContiguousSequence(user1, user2);
    for (int i = 0; i < res.size(); ++i) {
        std::cout << res[i] << std::endl;
    }
    
    return 0;
}
