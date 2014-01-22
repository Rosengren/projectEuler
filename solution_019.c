/* 
 * Project Euler - Problem 19
 * Counting Sundays
 *
 * You are given the following information:
 * 
 * 1 Jan 1900 was a Monday.
 * Thirty days has September,
 * April, June and November.
 * All the rest have thirty-one,
 * Saving February alone,
 * Which has twenty-eight, rain or shine.
 * And on leap years, twenty-nine.
 *
 * A leap year occurs on any year evenly divisible by 4, but not 
 * on a century unless it is divisible by 400. How many Sundays
 * fell on the first of the month during the twentieth century
 * (1 Jan 1901 to 31 Dec 2000)?
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * countSundays
 * 
 * Uses mod() to determine what day of the week any given sum
 * of days passed.
 */
int countSundays() {

	int monthYear[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int monthLeapYear[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int *monthDays, currentDay = 0, sundayCounter = 0, daysPassed = 0;

	// years to calculate
	for (int i = 1901; i <= 2000; i++) {
		
		monthDays = (i % 4 == 0) ? &monthLeapYear[0]: &monthYear[0];
		for (int months = 0; months < 12; months++) {
			if (currentDay + 1 == 6)
				sundayCounter++;
			daysPassed += monthDays[months];
			currentDay = daysPassed % 7;
		}
	}
	return sundayCounter;
}


int main(int argc, char const *argv[])
{
	int sundays = countSundays();
	printf("Number of Sundays falling on the first of the month between 1901 and 2000 is %d\n", sundays);
	return 0;
}

/*
 * readFile
 *
 * gets string from input file and saves it in inFile.
 */
