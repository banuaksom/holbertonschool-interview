#include <stdlib.h>
#include <stdio.h>

#include "palindrome.h"

int is_palindrome(unsigned long n)
{
    unsigned long rem, origin;
    unsigned long rev = 0;
    origin = n;

    while (n != 0) {
        rem = n % 10;
        rev = rev * 10 + rem;
        n /= 10;
    }

    if (origin == rev) {
        return (1);
    }
    else {
        return (0);
    }
}