/* 
 * Project Euler - Problem 6
 * Sum Square Difference
 *
 * The sum of the squares of the first ten natural numbers is,
 *
 * 12 + 22 + ... + 102 = 385
 * 
 * The square of the sum of the first ten natural numbers is,
 *
 * (1 + 2 + ... + 10)2 = 552 = 3025
 * 
 * Hence the difference between the sum of the squares of the
 * first ten natural numbers and the square of the sum is:
 * 3025 - 385 = 2640.
 * 
 * Find the difference between the sum of the squares of the 
 * first one hundred natural numbers and the square of the sum.
 *
 */

#include <stdio.h>
#include <stdlib.h>


/*
 * sumOfSquares
 *
 * Determine the sum of the square values of all numbers
 * between zero and a given number.
 */

int sumOfSquares(int num)
{
	int sum = 0;
	while (num > 0)
	{
		sum += num * num;
		num--;
	}	

	return sum;
}

/*
 * squareOfSums
 *
 * Determine the square of the sum of all numbers between
 * zero and a given number.
 */

int squareOfSums(int num)
{
	int sum = 0;
	while (num > 0)
	{
		sum += num;
		num--;
	}
	return sum * sum;
}

/** MAIN **/
int main(int argc, char *argv[])
{
	if (argc < 2) 
	{
		printf("Must pass integer value\n");
		return 0;
	}
	int num = atoi(argv[1]); // convert string to integer

	int squaredSum = squareOfSums(num);
	int sumSquares = sumOfSquares(num);

	printf("The sum square difference of %d is: %d\n",num, (squaredSum - sumSquares));
	return 0;
}

