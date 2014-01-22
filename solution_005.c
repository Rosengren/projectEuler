/* 
 * Project Euler - Problem 5
 * Smallest Multiple
 *
 * 2520 is the smallest number that can be divided by each
 * of the numbers from 1 to 10 without any remainder.
 *
 * What is the smallest positive number that is evenly 
 * divisible by all of the numbers from 1 to 20?
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* VARIABLES */
const int RANGE = 20;

/*
 * lcmOfRange
 *
 * Determines the lowest common multiple of a given
 * range of numbers.
 */

int lcmOfRange(int range)
{
	if (range < 2)
		return 1;

	int l = (range % 2 == 0) ? range - 2: range - 1;

	bool isMultiple = false;
	while(!isMultiple)
	{
		isMultiple = true;
		l += 2;
		for (int i = 1; i <= range; ++i)
		{
			if (l % i != 0)
				isMultiple = false;
		}
	}
	return l;
}

/** MAIN **/
int main(int argc, const char *argv[])
{
	printf("The smallest Mutliple of range 1-%d is: %d\n",RANGE, lcmOfRange(RANGE));
	return 0;
}