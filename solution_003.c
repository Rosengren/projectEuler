/* 
 * Project Euler - Problem 3
 * Largest Prime Factor
 *
 * The prime factors of 13195 are 5, 7, 13 and 29.
 *
 * What is the largest prime factor 
 * of the number 600851475143?
 */ 

#include <stdio.h>
#include <math.h>

/* VARIABLES */
const long NUMBER = 600851475143;

/*
 * prime
 *
 * find the largest prime factor of a given number.
 */

long prime(long num)
{
	int prime;		// used to check is factor is a prime number
	int factor = 3;	
	long largestPrime = 0;
	long squareNum = sqrt(num); // reduce number by the square
	while (num > 1 && factor <= squareNum) {

		// Determine if factor is a prime number
		for (prime = 2; prime <= factor - 1; prime++) {
			if (fmod(factor,prime) == 0)
				break;
		}
		// If factor is prime, check if num is divisible by factor
		if (factor == prime) {

			if (fmod(num, factor) == 0) {

				// Reduce num to increase loop speed
				while (fmod(num, factor) == 0) {num /= factor;}

				// new largest prime
				largestPrime = factor;
			}
		}
		factor += 2; // skip all even numbers;
	}

	return largestPrime;
}

/** MAIN **/
int main(int argc, char const *argv[])
{
	int l = prime(NUMBER);
	printf("Largest Prime Divisor of NUMBER is: %d\n", l);
	return 0;
}