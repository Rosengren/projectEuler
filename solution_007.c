/* 
 * Project Euler - Problem 7
 * 10001st Prime
 *
 * By listing the first six prime numbers: 
 * 2, 3, 5, 7, 11, and 13, 
 * we can see that the 6th prime is 13.
 * What is the 10 001st prime number? 
 */

#include <stdio.h>
#include <stdlib.h>

/* PRIME NUMBER */
const int PRIME = 10001;

/* findPrime
 * brute method of finding the desired prime number
 *
 * This function iterates through every number between
 * 1 and the desired prime number is reached. To check
 * whether a value is prime, each number is devided by
 * every value below itself. Once a divisor is found,
 * the while loop jumps to the subsequent number. 
 * 
 */

int findPrime(int num) 
{
	int i, j = 0, k = 0;
	int currPrime = 1;

	while (k <= num)
	{
		j += 1;
		for (i = 2; i < j; i++)
		{
			if (j % i == 0)
				goto loop;
		}
		currPrime = j;
		k++;
		loop: ;
	}
	return currPrime;	

}

int main(int argc, char const *argv[])
{

	int num = findPrime(PRIME);

	printf("The %dth prime is: %d\n", PRIME, num);
	return 0;
}  