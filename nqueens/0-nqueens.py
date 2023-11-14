#!/usr/bin/python3
import sys

def is_safe(board, row, col, n):
    # Check if there is a queen in the same column
    for i in range(row):
        if board[i][col] == 1:
            return False

    # Check upper diagonal on left side
    for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False

    # Check upper diagonal on right side
    for i, j in zip(range(row, -1, -1), range(col, n)):
        if board[i][j] == 1:
            return False

    return True

def solve_nqueens(board, row, n):
    if row == n:
        # Print the solution
        for i in range(n):
            print(' '.join(map(str, board[i])))
        print()
        return

    for col in range(n):
        if is_safe(board, row, col, n):
            # Place queen and move to the next row
            board[row][col] = 1
            solve_nqueens(board, row + 1, n)

            # Backtrack: undo the move
            board[row][col] = 0

def nqueens_solver(n):
    if not n.isdigit():
        print("N must be a number")
        sys.exit(1)

    n = int(n)

    if n < 4:
        print("N must be at least 4")
        sys.exit(1)

    board = [[0 for _ in range(n)] for _ in range(n)]
    solve_nqueens(board, 0, n)

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    nqueens_solver(sys.argv[1])
