/* 
 * Problem 22
 * Names Scores
 *
 * Using names.txt (right click and 'Save Link/Target As...'), 
 * a 46K text file containing over five-thousand first names, 
 * begin by sorting it into alphabetical order. Then working 
 * out the alphabetical value for each name, multiply this 
 * value by its alphabetical position in the list to obtain a
 * name score.
 *
 * For example, when the list is sorted into alphabetical order,
 * COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th
 * name in the list. So, COLIN would obtain a score of 938  53 = 49714.
 *
 * What is the total of all the name scores in the file?
 */

#include <stdio.h>
#include <math.h>

 // VARIABLES
 char *INPUT_FILE = "strings/names";


 FILE *infile;
 unsigned const CHAR_OFFSET = 48;
 long long score;

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
 	readFile(INPUT_FILE);
 	return 0;
 }