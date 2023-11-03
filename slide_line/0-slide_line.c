#include "slide_line.h"
#include <stddef.h>

#define SLIDE_LEFT 0
#define SLIDE_RIGHT 1

/**
 * slide_line - Slide and merge an array of integers to the left or right.
 * @line: Pointer to the array of integers.
 * @size: Number of elements in the array.
 * @direction: SLIDE_LEFT or SLIDE_RIGHT.
 * Return: 1 upon success, 0 upon failure.
 */
int slide_line(int *line, size_t size, int direction) {
    if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT) {
        return 0;  /* Invalid direction */
    }

    if (direction == SLIDE_LEFT) {
        /* Slide and merge to the left */
        size_t i, j;
        for (i = 0; i < size; i++) {
            if (line[i] == 0) {
                for (j = i + 1; j < size; j++) {
                    if (line[j] != 0) {
                        line[i] = line[j];
                        line[j] = 0;
                        break;
                    }
                }
            }
            for (j = i + 1; j < size; j++) {
                if (line[j] == line[i]) {
                    line[i] *= 2;
                    line[j] = 0;
                    break;
                } else if (line[j] != 0) {
                    break;
                }
            }
        }
    } else if (direction == SLIDE_RIGHT) {
        /* Slide and merge to the right */
        size_t i, j;
        for (i = size - 1; i < size; i--) {
            if (line[i] == 0) {
                for (j = i - 1; j < size; j--) {
                    if (line[j] != 0) {
                        line[i] = line[j];
                        line[j] = 0;
                        break;
                    }
                }
            }
            for (j = i - 1; j < size; j--) {
                if (line[j] == line[i]) {
                    line[i] *= 2;
                    line[j] = 0;
                    break;
                } else if (line[j] != 0) {
                    break;
                }
            }
        }
    }
    return 1;  /* Success */
}
