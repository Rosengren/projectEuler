/* 
 * Project Euler - Problem 14
 * Largest Collatz Sequence
 *
 * The following iterative sequence is defined for the set of 
 * positive integers:
 * 
 * n -> n/2 (n is even)
 * n -> 3n + 1 (n is odd)
 * 
 * Using the rule above and starting with 13, we generate the 
 * following sequence:
 * 
 * 13 -> 40 -> 20 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1
 *
 * It can be seen that this sequence (starting at 13 and finish-
 * ing at 1) contains 10 terms. Although it has not been proved 
 * yet (Collatz Problem), it is thought that all starting numbers
 * finish at 1.
 * 
 * Which starting number, under one million, produces the longest
 * chain?
 * 
 * NOTE: Once the chain starts the terms are allowed to go above 
 * one million.
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * largestCollatzNumber
 * 
 * In order to be efficient, this function stores the sequences
 * in a cache (array) so that identical sequences do not need to
 * be re-calculated.
 */

 /** Largest Starting Number **/
 const int NUMBER = 1000000;

int largestCollatzNumber() {

	int sequenceLength = 0;
	int startingNumber = 0;
	long sequence;

	int cache[number + 1];

	//Initialize cache
	for (int i = 0; i < NUMBER; i++)
	{
		cache[i] = -1;
	}

	cache[1] = 1;

	for (int i = 2; i <= NUMBER; i++)
	{
		sequence = i;
		int k = 0; // length of sequence
		while (sequence != 1 && sequence >= i) {
			k++;
			if ((sequence % 2) == 0)
				sequence /= 2;
			else
				sequence = sequence * 3 + 1;
		}

		//store result in cache
		cache[i] = k + cache[sequence];

		//Check if sequence is the best solution
		if (cache[i] > sequenceLength) {
			sequenceLength = cache[i];
			startingNumber = i;
		}
	}

	printf("The largest chain is: %d\n", startingNumber);
}

int main(int argc, char const *argv[]) {
	largestCollatzNumber();
	return 0;
}