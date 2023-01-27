#!/usr/bin/python3
""" Rotate 2d matrix
"""


def rotate_2d_matrix(matrix):
    """
    Function that rotates a 2d matrix
    Args:
        matrix ([type]): [description]
    """
    matrix.reverse()
    m = [i.copy()
         for i in matrix]
    for i, row in enumerate(m):
        for j, col in enumerate(row):
            matrix[j][i] = m[i][j]