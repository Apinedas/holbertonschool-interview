#include "palindrome.h"
#include <stdio.h>

/**
 * is_palindrome - Checks if a long int is Palindrome
 * @n: Number to check
 * Return: 1 if n is a palindrome, and 0 otherwise
 */

int is_palindrome(unsigned long n) {
    unsigned long first_digit = n, last_digit = 0, counter = 0, minuend = 1;

    if (n < 10)
        return 1;

    last_digit = n % 10;

    while (first_digit > 10)
    {
        first_digit /= 10;
        counter += 1;
    }

    while (counter > 0)
    {
        minuend *= 10;
        counter--;
    }
    
    minuend *= first_digit;

    if (first_digit != last_digit)
        return (0);
    
    return (is_palindrome(((n - minuend) / 10)));
}
