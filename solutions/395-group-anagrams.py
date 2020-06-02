"""
Given an array of strings, group anagrams together.

For example, given the following array:

['eat', 'ate', 'apt', 'pat', 'tea', 'now']
Return:

[['eat', 'ate', 'tea'],
 ['apt', 'pat'],
 ['now']]
 
"""

import collections


def groupAnagrams(listStr):
    result = collections.defaultdict(list)
    
    for string in listStr:
        count = [0] * 26
        
        for char in string:
            count[ord(char) - ord('a')] += 1
        result[tuple(count)].append(string)
        
    return result.values()
    
    
if __name__ == "__main__":
    listStr = ['eat', 'ate', 'apt', 'pat', 'tea', 'now']
    
    print(groupAnagrams(listStr))
