/* 
 * Problem 21
 * Amicable Numbers
 *
 * Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
 * If d(a) = b and d(b) = a, where a  b, then a and b are an amicable pair and each of a and b are called amicable numbers.
 * 
 * For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.
 * 
 * Evaluate the sum of all the amicable numbers under 10000.
 */
#include <stdio.h>
#include <math.h>

/** VARIABLES **/
const int UPPER_LIMIT = 10000;

 int div_sum[UPPER_LIMIT];

/*
 * sievePrimeDivisors
 *
 * Calculate all prime divisors below UPPER_LIMIT and sum
 * them together
 */
void sievePrimeDivisors() {

	// initialize each entry to 1;
	for (int i = 0; i < UPPER_LIMIT; ++i) 
		div_sum[i] = 1;

	for (int i = 2; i < (int)(UPPER_LIMIT / 2) + 1; ++i)
	{
		for (int j = i; j < UPPER_LIMIT; j += i)
		{
			if (j != i)
				div_sum[j] += i;
		}
	}
}

int sumAmicibleNumbers(int upperLimit) {

	int sumAmicible = 0;
	for (int i = 1; i < upperLimit; i++)
		if (div_sum[i] < upperLimit)
			if (div_sum[div_sum[i]] == i && div_sum[i] != i)
				sumAmicible += div_sum[div_sum[i]];

	printf("The sum is: %d\n", sumAmicible);
	return sumAmicible;
}


/** Brute force **/
int getAmicableSum(int range) {
	int sum, asum;
 	int anum = 0;

 	for (int num = 2; num < range; ++num)
 	{
 		sum = asum = 0;
 		for (int i = 1; i < num; ++i)
 		{
 			if (num % i == 0)
 				sum += i;
 		}

 		for (int i = 1; i < sum; ++i)
 		{
 			if (sum % i == 0)
 				asum += i;
 		}

 		if (num == asum && num != sum) {
 			anum += num;
 			printf("%d\n",anum);
 		}
 	}

 	printf("The sum is: %d\n", anum);
 	return anum;
}

 int main(int argc, char const *argv[])
 {
 	sievePrimeDivisors();
 	sumAmicibleNumbers(UPPER_LIMIT);
 	// betterMethod(10000);
 	// getAmicableSum(10000);
 	return 0;
 }