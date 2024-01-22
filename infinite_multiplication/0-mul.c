#include "holberton.h"
#include <stdlib.h>

/**
 * error_and_exit - Prints "Error" and exits with status 98.
 */
void error_and_exit(void)
{
    char *error_msg = "Error\n";

    while (*error_msg)
    {
        _putchar(*error_msg);
        error_msg++;
    }

    exit(98);
}

/**
 * is_digit - Checks if a string contains only digits.
 * @str: The input string.
 * Return: 1 if all characters are digits, 0 otherwise.
 */
int is_digit(char *str)
{
    while (*str)
    {
        if (*str < '0' || *str > '9')
            return 0;
        str++;
    }
    return 1;
}

/**
 * multiply - Multiplies two positive numbers and prints the result.
 * @num1: The first number.
 * @num2: The second number.
 */
void multiply(char *num1, char *num2)
{
    /* Your multiplication logic goes here */
    /* Print the result using _putchar */
    (void)num1;
    (void)num2;
}

int main(int argc, char *argv[])
{
    if (argc != 3 || !is_digit(argv[1]) || !is_digit(argv[2]))
        error_and_exit();

    multiply(argv[1], argv[2]);

    return 0;
}
