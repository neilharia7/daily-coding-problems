/*
This problem was asked by Yahoo.

Write an algorithm that computes the reversal of a directed graph. 
For example, if a graph consists of A -> B -> C, it should become A <- B <- C.
*/

#include<bits/stdc++.h>
using namespace std;

void reverseGraph(std::vector<int> reverse[], std::vector<int> v[], int nodes) {
    for (int i = 0; i < nodes; ++i) {
        for(int j = 0; j < v[i].size(); ++j) {
            reverse[v[i][j].push_back(i)]
        }
    }
    
    for (int i = nodes - 1; i >= 0; --i) {
        for(int j = reverse[i].size() - 1; j >= 0; --j) {
            std::cout << i << " -> " << reverse[i][j] << ", ";
        }
    }
}

int main() {
    int nodes = 3;
    std::vector<int> v[3];
    std::vector<int> reverse[3];
    
    v[0].push_back(1);
    v[1].push_back(2);

    reverseGraph(reverse, v, nodes);
    return 0;
}
