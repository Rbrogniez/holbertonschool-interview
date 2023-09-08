#!/usr/bin/python3
"""
Base case: If n is less than or equal to 1, no operations are needed.
"""


def minOperations(n):
    if n <= 1:
        return 0  # Return 0 for values less than or equal to 1

    operations = 0
    divisor = 2

    while n > 1:
        while n % divisor == 0:
            operations += divisor
            n //= divisor
        divisor += 1

    return operations
