"""
This problem was asked by Facebook.

Given a list of strictly positive integers, 
partition the list into 3 contiguous partitions which each sum up to the same value. 
If not possible, return null.

For example, given the following list:

[3, 5, 8, 0, 8]
Return the following 3 partitions:

[[3, 5],
 [8, 0],
 [8]]
Which each add up to 8.
"""

def partition(ls: list):
    total = sum(ls)
    
    if total % 3 != 0 or len(ls) < 3:
        return None
    
    block = total / 3
    new_ls = []
    idx, temp = 0, 0
    for i in range(len(ls)):
        if ls[i] > block:
            return None
        
        temp += ls[i]
        
        if temp > block:
            return None
        elif temp == block:
            new_ls.append(ls[idx:i + 1])
            temp = 0
            idx = i + 1
 
    print(new_ls)


if __name__ == "__main__":
    ls = [3, 5, 8, 0, 8]
    partition(ls)
