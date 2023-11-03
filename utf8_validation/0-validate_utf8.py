#!/usr/bin/python3
"""
UTF validation
"""


def validUTF8(data):
    """Determines if a given data set represents a valid UTF-8 encoding"""

    isFirst = 1
    nbBytes = 0

    for n in data:
        n = n & 0xFF
        nbOnes = count_consecutive_ones(n)

        if isFirst == 1:
            if nbOnes != 0:
                nbBytes = nbOnes - 1
                if nbBytes >= 4:
                    return False
                isFirst = 0
        else:
            if nbOnes != 1:
                return False
            nbBytes -= 1
            if nbBytes == 0:
                isFirst = 1

    if nbBytes != 0:
        return False
    return True


def count_consecutive_ones(n):
    """Count the number of 1 at the start of an int"""
    binary_representation = bin(n)[2:].zfill(8)
    count = 0

    for bit in binary_representation:
        if bit == '1':
            count += 1
        else:
            break

    return count
