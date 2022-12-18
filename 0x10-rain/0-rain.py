#!/usr/bin/python3
"""
calculate how many square units of water will be retained after it rains
"""


def rain(walls):
    """function"""
    if len(walls) == 0 or type(walls) != list:
        return 0
    left = [0] * len(walls)
    right = [0] * len(walls)
    water = 0
    left[0] = walls[0]
    for i in range(1, len(walls)):
        left[i] = max(left[i - 1], walls[i])
    right[len(walls) - 1] = walls[len(walls) - 1]
    for i in range(len(walls) - 2, -1, -1):
        right[i] = max(right[i + 1], walls[i])
    for i in range(0, len(walls)):
        water += min(left[i], right[i]) - walls[i]
    return water