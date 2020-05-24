"""
Given a string, sort it in decreasing order based on the frequency of characters. 
If there are multiple possible solutions, return any of them.

For example, given the string tweet, return tteew. eettw would also be acceptable.
"""


def sortedChars(string: str) -> str:
    dictionary = {}
    new_string = ""
    
    for char in string:
        if char not in dictionary:
            dictionary[char] = 1
        else:
            dictionary[char] += 1

    dictionary = {k: v for k, v in sorted(dictionary.items(), key=lambda item: item[1], reverse=True)}
    
    for k, v in dictionary.items():
        new_string += k * v
    return new_string

if __name__ == "__main__":
    print(sortedChars("tweet"))
    
