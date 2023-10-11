int is_palindrome(unsigned long n)
{
	unsigned long nb = n;
	unsigned long inverse = 0;

    while (nb > 0) {
        inverse = inverse * 10 + nb % 10;
        nb = nb / 10;
    }

    if (n == inverse)
        return 1;
    else
        return 0;

}
