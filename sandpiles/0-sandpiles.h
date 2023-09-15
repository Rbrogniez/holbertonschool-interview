#include <stdio.h>

#define SIZE 3

// Function to print a sandpile
void printSandpile(int grid[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a sandpile is stable
int isStable(int grid[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (grid[i][j] > 3) {
                return 0; // Unstable
            }
        }
    }
    return 1; // Stable
}

// Function to perform a toppling operation on a sandpile
void topple(int grid[SIZE][SIZE], int i, int j) {
    grid[i][j] -= 4;
    if (i > 0) grid[i - 1][j]++;
    if (i < SIZE - 1) grid[i + 1][j]++;
    if (j > 0) grid[i][j - 1]++;
    if (j < SIZE - 1) grid[i][j + 1]++;
}

// Function to compute the sum of two sandpiles
void sandpiles_sum(int grid1[SIZE][SIZE], int grid2[SIZE][SIZE]) {
    // Add the two sandpiles together
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grid1[i][j] += grid2[i][j];
        }
    }

    // Perform toppling until the resulting sandpile is stable
    while (!isStable(grid1)) {
        printf("Unstable Sandpile:\n");
        printSandpile(grid1);
        int temp[SIZE][SIZE];

        // Copy the current state of grid1 to temp
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                temp[i][j] = grid1[i][j];
            }
        }

        // Perform toppling on temp
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (temp[i][j] > 3) {
                    topple(grid1, i, j);
                }
            }
        }
    }
