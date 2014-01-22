/* 
 * Project Euler - Problem 1
 * Multiples of 3 and 5
 *
 * The sum of all multiples of a number below a given value can
 * be generalized to:
 *
 * n * p * (p + 1) / 2
 *
 * where:
 * n = multiple
 * p = Given Value divided by 2
 */

#include <stdio.h>

/* VARIABLES */
const int TARGET = 999;

/*
 * sumDivisibleBy
 *
 * finds the number of multiples of a given value
 */

int sumDivisibleBy(int n) {

	int p = TARGET / n;
	return n * p * (p + 1) / 2;
}

/** MAIN **/
int main()
{
	int sum = sumDivisibleBy(3) + sumDivisibleBy(5) - sumDivisibleBy(15);
    printf("The sum of all multiples of 3 and 5 below 1000 is: %d\n", sum);

    return 0;

}