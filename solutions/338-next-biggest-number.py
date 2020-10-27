"""
This problem was asked by Facebook.

Given an integer n, find the next biggest integer with the same number of 1-bits on. 
For example, given the number 6 (0110 in binary), return 9 (1001).
"""

def getCount(value: int) -> int:
    return str(bin(value))[2:].count('1')
    
    
if __name__ == "__main__":
    number, increment = 6, 1
    initial_count = getCount(number)
    next_number = number + 1
    while True:
        intermidiate_count = getCount(next_number)
        if intermidiate_count == initial_count:
            print(next_number, str(bin(next_number))[2:])  # 9 1001
            break
        next_number += 1

