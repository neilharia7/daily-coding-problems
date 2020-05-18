/*
This problem was asked by Google.

The h-index is a metric used to measure the impact and productivity of a scientist or researcher.

A scientist has index h if h of their N papers have at least h citations each, 
and the other N - h papers have no more than h citations each. 
If there are multiple possible values for h, the maximum value is used.

Given an array of natural numbers, with each value representing the number of citations of a researcher's paper,
return the h-index of that researcher.

For example, if the array was:

[4, 0, 0, 2, 3]
This means the researcher has 5 papers with 4, 1, 0, 2, and 3 citations respectively. 
The h-index for this researcher is 2, since they have 2 papers with at least 2 citations and the 
remaining 3 papers have no more than 2 citations.
*/

#include<bits/stdc++.h>
using namespace std;

int hIndex(vector<int>& v) {
    sort(v.begin(), v.end(), greater<int>()); 
    
    for (int idx = 0; idx < v.size(); ++idx) {
        if (v[idx] < idx + 1)
            return idx;
    }
    
    return v.size();
}

int main() {
	std::vector<int> v = {4, 0, 0, 2, 3};
	std::cout << hIndex(v) << std::endl;
	return 0;
}
