"""
This problem was asked by Google.

The area of a circle is defined as πr^2. Estimate π to 3 decimal places using a Monte Carlo method.

Hint: The basic equation of a circle is x2 + y2 = r2.
"""

from random import random


def piEstimate(testCases: int, radius: int):
    r2 = radius ** 2
    
    counter = 0
    for _ in range(testCases):
        x2, y2 = radius * random(), radius * random()
        if (x2 ** 2 + y2 ** 2) < r2:
            counter += 1

    print(round((4 * counter / testCases), 3))


if __name__ == "__main__":
    piEstimate(1000000, 3)
    
