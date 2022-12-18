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


def solveNQueens(n):
    col = set()
    posDiag = set()
    negDiag = set()

    res = []
    board = [["."] * n for _ in range(n)]

    def backtrack(r):
        if r == n:
            copy = ["".join(row) for row in board]
            res.append(copy)
            return

        for c in range(n):
            if c in col or (r + c) in posDiag or (r - c) in negDiag:
                continue

            col.add(c)
            posDiag.add(r + c)
            negDiag.add(r - c)
            board[r][c] = "Q"

            backtrack(r + 1)

            col.remove(c)
            posDiag.remove(r + c)
            negDiag.remove(r - c)
            board[r][c] = "."

    backtrack(0)
    return res


results = []
boards = solveNQueens(N)
for board in range(len(boards)):
    results.append([])
    for row in range(len(boards[board])):
        for col in range(len(boards[board][row])):
            if boards[board][row][col] == 'Q':
                results[board].append([row, col])

for res in results:
    print(res)
