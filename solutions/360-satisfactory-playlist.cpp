/*
This problem was asked by Spotify.

You have access to ranked lists of songs for various users. 
Each song is represented as an integer, and more preferred songs appear earlier in each list. 
For example, the list [4, 1, 7] indicates that a user likes song 4 the best, followed by songs 1 and 7.

Given a set of these ranked lists, interleave them to create a playlist that satisfies everyone's priorities.

For example, suppose your input is {[1, 7, 3], [2, 1, 6, 7, 9], [3, 9, 5]}. 
In this case a satisfactory playlist could be [2, 1, 6, 7, 3, 9, 5].
*/


#include<bits/stdc++.h>
using namespace std;

bool sortByVal(const pair<int, int> a, const pair<int, int> b) {
    return a.second > b.second;
}

void satisfactoryPlaylist(vector<vector<int>> playlist) {
    
    std::unordered_map<int, float> mapper;
    std::unordered_map<int, float>::iterator itr;
    
    for (int i = 0; i < playlist.size(); ++i) {
        
        int len = playlist[i].size();
        int weightage = ((len + 1) * len) / 2;
        
        for (int j = 0; j < len; ++j) {
            
            if (!mapper.count(playlist[i][j])) {
                mapper.insert(pair<int, int>(playlist[i][j], 0));
            }
            itr = mapper.find(playlist[i][j]);
            itr->second += (float) weightage / (float)(j + 1);
        }
    }
    
    std::vector<pair<int, int>> v;
    
    for (itr = mapper.begin(); itr != mapper.end(); ++itr) {
        std::cout << "item " << itr->first << " weightage " << itr->second << std::endl;
        v.push_back(make_pair(itr->first, itr->second));
    }
    
    std::cout << "--------------------" << std::endl;
    std::sort(v.begin(), v.end(), sortByVal);
    
    for (auto& p: v) {
        std::cout << p.first << " ";
    }
} 

int main() {
    std::vector<vector<int >> playlist = {{1, 7, 3}, {2, 1, 6, 7, 9}, {3, 9, 5}};
    satisfactoryPlaylist(playlist);
    
    return 0;
}
