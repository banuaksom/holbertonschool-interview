#include <stdlib.h>
#include <stdio.h>

#include "palindrome.h"

/**
 * is_palindrome - checks if integer is a palindrome
 * @n: number to check
 * Return: 1 if palindrome, 0 - otherwise
 */
int is_palindrome(unsigned long n)
{
	unsigned long rem, origin = n;
	unsigned long rev = 0;


	while (n != 0)
	{
		rem = n % 10;
		rev = rev * 10 + rem;
		n /= 10;
	}

	if (origin == rev)
		return (1);
	else
		return (0);
}
