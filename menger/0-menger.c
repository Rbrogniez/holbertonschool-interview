#include <stdio.h>
#include <math.h>

void drawSquare(int size);

/**
 * menger - Draws a 2D Menger Sponge
 * @level: Level of the Menger Sponge to draw
 */
void menger(int level)
{
    if (level < 0)
        return;

    int size = pow(3, level);

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i % 3 == 1 && j % 3 == 1)
            {
                // Center of the Menger Sponge, leave empty
                printf(" ");
            }
            else
            {
                // Draw the Menger Sponge
                drawSquare(level);
            }
        }
        printf("\n");
    }
}

/**
 * drawSquare - Draws a square for the Menger Sponge
 * @size: Size of the square
 */
void drawSquare(int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("#");
        }
    }
}
