/* 
 * Project Euler - Problem 11
 * Largest Product in a Grid
 *
 * What is the greatest product of four adjacent numbers in 
 * the same direction (up, down, left, right, or diagonally) 
 * in the 20 x 20 grid? (grid found in strings/grid)
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// VARIABLES
char *INPUT_FILE = "strings/numArray";


FILE *infile;
int grid[20][20];
unsigned const NUMBER_OFFSET = 48;
long largestProduct;

/*
 * buildArray
 *
 * constructs an array of arrays
 * with dimensions of vLength by hLength
 */
void buildArray(int vLength, int hLength) 
{
	char lineNums[hLength * 2];
	for (int v = 0; v < vLength; v++) {

		fgets(lineNums, hLength * 2 + 2, infile);

		int h = 0;
		int i = 0; // getting 2-digit numbers from file
		while (h < hLength) {
			grid[v][h++] = (lineNums[i] - NUMBER_OFFSET) * 10 \
					+ lineNums[i + 1] - NUMBER_OFFSET;
			i += 2;
		}
	}
}

/*
 * hvScope
 *
 * Given the dimensions of an array of arrays
 * and the scope to be checked, this function
 * finds the largest product of a series of 
 * digits of length scope in the horizontal
 * and vertical directions
 */
int hvScope(int scope, int vLength, int hLength) {

	for (int v = 0; v < vLength - scope; v++) {
		for (int h = 0; h < hLength; h++) {

			int numH = 1;
			int numV = 1;
			int i = 1;
			while ( i < scope) {
				numH *= grid[v][h + i];
				numV *= grid[v + i++][h];
			}
			largestProduct = largestProduct > numH? largestProduct : numH;
			largestProduct = largestProduct > numV? largestProduct : numV;
		}
	}
	printf("Horizontal/Vertical largestProduct: %ld\n", largestProduct);
	return largestProduct;
}

/*
 * leftDiagScope
 *
 * Given the dimensions of an array of arrays and the 
 * scope to be checked, this function finds the largest
 * product in the left-diagonal direction
 *
 */
int leftDiagScope(int scope, int vLength, int hLength) {

	for (int h = 4; h < hLength; h++) {
		for (int v = 0; v < vLength - 5; v++) {

			int i = 0;
			int num = 1;
			while (i < scope)
				num *= grid[v + i][h - i++];

			largestProduct = largestProduct > num? largestProduct : num;
		}
	}
	printf("largestProduct: %ld\n", largestProduct);
	return largestProduct;

}

/*
 * rightDiagScope
 *
 * Given the dimensions of an array of arrays and the 
 * scope to be checked, this function finds the largest
 * product in the right-diagonal direction
 *
 */
int rightDiagScope(int scope, int vLength, int hLength) {

	for (int h = 0; h < hLength - 4; h++) {
		for (int v = 0; v < vLength - 5; v++) {

			int i = 0;
			int num = 1;
			while (i < scope)
				num *= grid[v + i][h + i++];

			largestProduct = largestProduct > num? largestProduct : num;
		}
	}
	printf("Right Diagonal largestProduct: %ld\n", largestProduct);
	return largestProduct;
}

/*
 * readFile
 *
 * gets string from input file and saves it in inFile.
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
int main(int argc, char const *argv[])
{

	// set initial product size
	largestProduct = 0;

	// Initialize and compare
	readFile(INPUT_FILE);
	buildArray(20, 20);

	int hvProduct = hvScope(4, 20, 20);
	int rightDiagProduct = rightDiagScope(4, 20, 20);
	int leftDiagProduct = leftDiagScope(4, 20, 20);

	largestProduct = largestProduct < hvProduct ? hvProduct : largestProduct;
	largestProduct = largestProduct < rightDiagProduct ? rightDiagProduct : largestProduct;
	largestProduct = largestProduct < leftDiagProduct ? leftDiagProduct : largestProduct;

	printf("The largest Product is : %ld\n", largestProduct);

	return 0;
}
