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
  int len1 = 0, len2 = 0;

    while (num1[len1])
        len1++;
    while (num2[len2])
        len2++;

    int result_len = len1 + len2;
    int *result = malloc(sizeof(int) * result_len);
    if (result == NULL)
        error_and_exit();

    /* Initialize the result array to 0 */
    for (int i = 0; i < result_len; i++)
        result[i] = 0;

    /* Multiply each digit and add to the result */
    for (int i = len1 - 1; i >= 0; i--)
    {
        int carry = 0;
        for (int j = len2 - 1; j >= 0; j--)
        {
            int mul = (num1[i] - '0') * (num2[j] - '0') + result[i + j + 1] + carry;
            result[i + j + 1] = mul % 10;
            carry = mul / 10;
        }
        result[i] += carry;
    }

    /* Print the result using _putchar */
    int start = 0;
    while (start < result_len - 1 && result[start] == 0)
        start++;

    for (int i = start; i < result_len; i++)
        _putchar(result[i] + '0');

    _putchar('\n');

    free(result);
}

int main(int argc, char *argv[])
{
    if (argc != 3 || !is_digit(argv[1]) || !is_digit(argv[2]))
        error_and_exit();

    multiply(argv[1], argv[2]);

    return 0;
}
