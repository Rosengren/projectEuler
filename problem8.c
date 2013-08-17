/* 
 * Project Euler - Problem 8
 * Largest Product in a Series
 *
 * Find the greatest product of five consecutive 
 * digits in the 1000-digit number.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned const NUMBER_OFFSET = 48;
FILE *infile;

// ASSIGN VALUES
const int SCOPE = 5; // number of values to multiply
char *INPUT_FILE = "strings/numArray"; // file with digits

/* 
 * product
 * 
 * Calculates the product of a given array
 * Requires array and its length
 */

int product(int num[], int arrayLength)
{
	unsigned int i = 0, p = 1;

	// multiply all terms in num[]
	while (i < arrayLength)
	{
		p *= num[i];
		i++;
	}
	// return product of num[]
	return p;
}

/*
 * maxProduct
 *
 * finds the highest product of a specified scope
 * within a string of digits.
 */

int maxProduct(int scope)
{
	int num[scope];
	int k, prod;

	// get first five digits
	for (int i = 0; i < scope; i++)
		num[i] = getc(infile) - NUMBER_OFFSET;

	// set current highest product
	int maxProd = product(num, scope);

	for (int j = 0; ; j++)
	{
		// shift-left digits
		for (k = 0; k < scope - 1; k++)
			num[k] = num[k + 1];

		// get new digit
		num[scope - 1] = getc(infile) - NUMBER_OFFSET;
		
		// check if end of string
		if (num[scope - 1] < 0)
			break;
		
		prod = product(num, scope);
		
		// compare new product with current product
		if (maxProd < prod)
			maxProd = prod;
	}

	return maxProd;
}

/*
 * readFile
 *
 * gets string from input file and saves it in
 * inFile.
 */

void readFile(char *filename)
{
	// read input file
	infile = fopen(filename, "r");

	if (infile == NULL) {
		printf("No such file exists\n");
		return;
	}
}

/** MAIN **/
int main(int argc, char *argv[])
{
	readFile(INPUT_FILE);
	printf("The largest product of %d consecutive numbers in %s: %d\n", SCOPE, INPUT_FILE, maxProduct(SCOPE));
	return 0;
}