"""
This problem was asked by Nextdoor.

Implement integer division without using the division operator. 
Your function should return a tuple of (dividend, remainder) and it should take two numbers, the product and divisor.

For example, calling divide(10, 3) should return (3, 1) since the divisor is 3 and the remainder is 1.

Bonus: Can you do it in O(log n) time?
"""

def integer_division(product: int, divisor: int): 
    prodNeg, divNeg, res = 0, 0, 0
    if divisor == 0:
        raise Exception("Division by Zero")
    
    if divisor < 0:
        divNeg, divisor = 1, -divisor
    
    if product < 0:
        prodNeg, product = 1, -product
        
    while product >= 0:
        product -= divisor
        res += 1
    
    rem = product + divisor
    res -= 1
    
    if divNeg:
        res, rem = -res, -rem
    
    if prodNeg:
        res, rem = -res, -rem
        
    return res, rem
        

if __name__ == "__main__":
    print(integer_division(10, 3))
