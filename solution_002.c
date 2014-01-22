/* 
 * Project Euler - Problem 2
 * Even Fibonacci Numbers
 *
 * Each new term in the Fibonacci sequence is generated 
 * by adding the previous two terms. By starting with 1
 * and 2, the first 10 terms will be:
 *
 * 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
 *
 * By considering the terms in the Fibonacci sequence whose
 * values do not exceed four million, find the sum of the 
 * even-valued terms.
 */

#include <stdio.h>

/*
 * evenFibonacci
 *
 * calculates the even sum of fibonacci numbers between
 * zero and maxNumber.
 * Uses the principle that every third nuumber in the
 * sequence is even.
 */
int evenFibonacci(int maxNumber) {
	long fib[] = {2,0};
	int i = 0;
	long summed = 0;

	while (fib[i] < maxNumber) {
		summed += fib[i];
		i = (i + 1) % 2;

		// 4 * F(n - 3) + F(n - 6)
		fib[i] = 4 * fib[(i + 1) % 2] + fib[i];
	}

	return summed;
}

int main(int argc, char const *argv[])
{

	int evenSum = evenFibonacci(4000000);
	printf("Sum of even valued Fibonacci numbers: %d\n", evenSum);

	return 0;
}
