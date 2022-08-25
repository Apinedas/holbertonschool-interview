#!/usr/bin/python3
"""Module to calc min number of operations using brute force"""

def minOperations(n):
    i = 2
    if n >= 1:
        while n % i != 0:
            i += 1
        return i + minOperations(int(n/i))
    return 0
