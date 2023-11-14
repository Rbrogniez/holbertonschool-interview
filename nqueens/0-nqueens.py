#!/usr/bin/python3
import sys

def print_usage_and_exit():
    print("Usage: nqueens N")
    sys.exit(1)

def solve_nqueens(N):
    if not N.isdigit():
        print("N must be a number")
        sys.exit(1)

    N = int(N)

    if N < 4:
        print("N must be at least 4")
        sys.exit(1)

    def is_safe(board, row, col):
        # Check if there is a queen in the same column
        for i in range(row):
            if board[i] == col or board[i] - i == col - row or board[i] + i == col + row:
                return False
        return True

    def solve(board, row):
        if row == N:
            print([[i, board[i]] for i in range(N)])
            return

        for col in range(N):
            if is_safe(board, row, col):
                board[row] = col
                solve(board, row + 1)

    solve([0] * N, 0)

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print_usage_and_exit()

    N = sys.argv[1]
    solve_nqueens(N)
