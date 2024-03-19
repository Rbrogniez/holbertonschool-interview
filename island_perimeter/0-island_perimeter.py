#!/usr/bin/python3
"""Module that calculates the perimeter of an island in a grid"""


def island_perimeter(grid):
    """
    Calculates the perimeter of the island described in the given grid.

    Parameters:
    - grid : list[list[int]]
        A list of lists of integers representing the grid of the island.
        Each integer represents a cell:
            - 0 represents water.
            - 1 represents land.
        The grid is completely surrounded by water.
        There is only one island (or nothing).
        The island doesn't have "lakes" (water inside that isn't
        connected to the water surrounding the island).

    Returns:
    - perimeter : int
        The total perimeter of the island.
    """
    perimeter = 0

    # Check each cell in the grid
    for i in range(len(grid)):
        for j in range(len(grid[0])):
            if grid[i][j] == 1:  # If the cell represents land
                # Check each side of the cell
                # If the side is water r outside the grid,add 1 to the perimeter
                if i == 0 or grid[i - 1][j] == 0:
                    perimeter += 1
                if i == len(grid) - 1 or grid[i + 1][j] == 0:
                    perimeter += 1
                if j == 0 or grid[i][j - 1] == 0:
                    perimeter += 1
                if j == len(grid[0]) - 1 or grid[i][j + 1] == 0:
                    perimeter += 1

    return perimeter
