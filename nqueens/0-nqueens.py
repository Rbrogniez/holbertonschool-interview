#!/usr/bin/python3

import sys

# Function to check if placing a queen at a specific position is safe


def is_safe(board, row, col, n):
    # Check if there is a queen in the same column or along diagonals
    for i in range(row):
        if board[i][1] == col or \
           board[i][1] - i == col - row or \
           board[i][1] + i == col + row:
            return False
    return True

# Recursive function to solve the N-Queens problem


def solve_nqueens(board, row, n, solutions):
    # If all queens are placed, add the solution to the list
    if row == n:
        solutions.append(board[:])  # Add a copy of the solution to the list
        return
    # Try placing a queen in each column of the current row
    for col in range(n):
        if is_safe(board, row, col, n):
            board[row] = [row, col]  # Place the queen
            solve_nqueens(board, row + 1, n, solutions)

# Main function to initialize the N-Queens solver


def nqueens_solver(n):
    # Check if the input is a valid integer
    if not n.isdigit():
        print("N must be a number")
        sys.exit(1)

    n = int(n)

    # Check if the board size is at least 4
    if n < 4:
        print("N must be at least 4")
        sys.exit(1)

    # Initialize the chessboard with placeholders for queens
    board = [[-1, -1] for _ in range(n)]
    solutions = []  # List to store the solutions
    solve_nqueens(board, 0, n, solutions)

    # Print each solution
    for solution in solutions:
        print(solution)

# Check if the script is executed as the main module
if __name__ == "__main__":
    # Check if the correct number of command-line arguments is provided
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    # Call the N-Queens solver with the specified board size
    nqueens_solver(sys.argv[1])
