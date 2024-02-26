#!/usr/bin/python3
"""
Main file for testing
"""


import sys


makeChange = __import__('0-making_change').makeChange

print(makeChange([1, 3, 7], -10))
