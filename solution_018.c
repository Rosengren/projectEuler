/* 
 * Project Euler - Problem 18
 * Maximum Path Sum I
 *
 * By starting at the top of the triangle below and moving 
 * to adjacent numbers on the row below, the maximum total
 * from top to bottom is 23.
 * 
 * 3
 * 7 4
 * 2 4 6
 * 8 5 9 3
 * 
 * That is, 3 + 7 + 4 + 9 = 23.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

FILE *infile;
unsigned const NUMBER_OFFSET = 48;

/* VARIABLES */
const int HEIGHT; // height of triangle
char *INPUT_FILE = "strings/triangle"; // input file location/name

int grid[HEIGHT][HEIGHT];

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

/*
 * buildGrid
 *
 * construct a grid (array of arrays) of size height x height
 * containing the valuse in the triangle
 */

void buildGrid(int height) {

	char lineNums[height * (3) + 2];
	int j, y, x = 0;
	for (int i = 1; i <= height; ++i)
	{
		fgets(lineNums, sizeof(lineNums), infile);

		j = 0, y = 0;
		while (j <= 3 * (i - 1))
		{	
			grid[x][y] = (lineNums[j] - NUMBER_OFFSET) * 10 \
						+ lineNums[j + 1] - NUMBER_OFFSET;
			j += 3;
			y++;
		}
		while (y < 15) {
			grid[x][y] = 0;
			y++;
		}
		x++;
	}
}

/*
 * dynamicSolution
 *
 * bottom-up approach where each row (excluding the last one)
 * is summed with the highest value below within reach. This
 * is repeated until the top value is reached. The array
 * constantly changes and are equal to the highest-value path
 * below it. This function only requires one pass through each
 * level of the triangle. Efficiency: O(n)
 *
 */

void dynamicSolution(int lines) {

	for (int i = lines - 2; i >= 0 ; i--) {
		for (int j = 0; j <= i; j++) {
			grid[i][j] += fmax(grid[i + 1][j], grid[i + 1][j + 1]);
		}
	}
}

/** MAIN **/
int main(int argc, char const *argv[])
{
	// Initialize and run
	readFile(INPUT_FILE);
	buildGrid(HEIGHT);
	dynamicSolution(HEIGHT);
	printf("The largest value path is: %d\n", grid[0][0]);
	return 0;
}