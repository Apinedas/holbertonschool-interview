#!/usr/bin/python3
"""N queens module"""

import sys

if (len(sys.argv) != 2):
    print("Usage: nqueens N")
    exit(1)

try:
    N = int(sys.argv[1])
except Exception:
    print("N must be a number")
    exit(1)

if (N < 4):
    print("N must be at least 4")
    exit(1)


def nqueens(actual_row, actual_col, N):

    attacked_pos_diags = []
    attacked_neg_diags = []
    attacked_rows = []
    attacked_cols = []
    on_board_queens = []

    while actual_row < N:
        actual_pos_diag = actual_row - actual_col
        actual_neg_diag = actual_row + actual_col
        if actual_col < N and actual_row not in attacked_rows\
           and actual_col not in attacked_cols\
           and actual_pos_diag not in attacked_pos_diags\
           and actual_neg_diag not in attacked_neg_diags:
            attacked_rows.append(actual_row)
            attacked_cols.append(actual_col)
            attacked_pos_diags.append(actual_pos_diag)
            attacked_neg_diags.append(actual_neg_diag)
            on_board_queens.append([actual_row, actual_col])
            actual_row += 1
            actual_col = 0
        else:
            actual_col += 1
            if actual_row == 0 and actual_col >= N:
                return None
            if actual_col >= N:
                actual_row, actual_col = on_board_queens.pop(-1)
                actual_pos_diag = actual_row - actual_col
                actual_neg_diag = actual_row + actual_col
                attacked_rows.remove(actual_row)
                attacked_cols.remove(actual_col)
                attacked_pos_diags.remove(actual_pos_diag)
                attacked_neg_diags.remove(actual_neg_diag)
                actual_col += 1

    return (on_board_queens)


actual_row = 0
actual_col = 0
solutions = []

while actual_col < N:
    solution = nqueens(actual_row, actual_col, N)
    if solution:
        solutions.append(solution)
        actual_row, actual_col = solution[0]
    actual_col += 1

for solution in solutions:
    print(solution)
