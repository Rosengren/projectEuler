/* 
 * Project Euler - Problem 4
 * Largest Palindrome Product
 *
 * A palindromic number reads the same both ways. 
 * The largest palindrome made from the product of
 * two 2-digit numbers is 9009 = 91 99.
 * 
 * Find the largest palindrome made from the product 
 * of two 3-digit numbers.
 */

#include <stdio.h>

/* VARIABLES */
const int VALUE_LIMIT = 1000;

/*
 * palin
 *
 * determines whether a number is a palindrome or not
 * returns a boolean value (true if palindrome)
 */
bool palin(int num) 
{
	int reverse = 0;
	int temp = num;

	while (temp != 0)
	{
		reverse *= 10;
		reverse += temp % 10;
		temp /= 10;
	}

	if (num == reverse)
		return true;

	return false;
}

/*
 * largestPalindrome
 *
 * determines the largest palindrome between zero
 * and limit.
 */
int largestPalindrome(int limit)
{
	int largestPal = 0, pal = 0;
	for (int i = 100; i < limit; i++) {
		for (int k = 100; k < limit; k++) {
			pal = k * i;
			if (palin(pal) && pal > largestPal)
				largestPal = pal;
		}
	}

	return largestPal;
}

/** MAIN **/
int main(int argc, char const *argv[])
{
	printf("The Largest Number that is a palindrom is: %d\n",largestPalindrome(VALUE_LIMIT));
	return 0;
}