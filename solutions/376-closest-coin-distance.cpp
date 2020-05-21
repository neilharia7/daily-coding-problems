/*
You are writing an AI for a 2D map game. You are somewhere in a 2D grid, 
and there are coins strewn about over the map.

Given the position of all the coins and your current position, 
find the closest coin to you in terms of Manhattan distance. 
That is, you can move around up, down, left, and right, but not diagonally. 
If there are multiple possible closest coins, return any of them.

For example, given the following map, where you are x, coins are o, and empty spaces are . (top left is 0, 0):

---------------------
| . | . | x | . | o |
---------------------
| o | . | . | . | . |
---------------------
| o | . | . | . | o |
---------------------
| . | . | o | . | . |
---------------------
return (0, 4), since that coin is closest. This map would be represented in our question as:

Our position: (0, 2)
Coins: [(0, 4), (1, 0), (2, 0), (3, 2)]
*/

#include <bits/stdc++.h>
using namespace std;

int closestCoin(pair<int, int>pos, vector<pair<int, int> >& v) {
    int mi = INT_MAX;
    
    for (int i = 0; i < v.size(); ++i) {
        int distance = abs(pos.first - v[i].first) + abs(pos.second - v[i].second);
        
        if (mi > distance) {
            mi = distance;
        }
    }
    
    return mi;
}

int main() {
    
    pair<int, int> pos = make_pair(0, 2);
    
    std::vector<pair<int, int> > v = {
        make_pair(0, 4), 
        make_pair(1, 0), 
        make_pair(2, 0), 
        make_pair(3, 2)
    };
    std::cout << closestPossibleCoin(pos, v) << std::endl;
    
	return 0;
}
