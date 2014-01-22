/* 
 * Project Euler - Problem 10
 * Summation of primes
 *
 * The sum of the primes below 10 is:
 * 2 + 3 + 5 + 7 = 17.
 * 
 * Find the sum of all the primes below two million.
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>

/*
 * isPrime
 *
 * Determines whether a given number is prime
 *
 * For efficienct, the function only tries to divide
 * the number by its square root as any value above
 * would also be divisible by a value below.
 */

int isPrime(int a)
{
    int limit = sqrt(a);
    for(int i = 5;i <= limit; i = i + 4)
    {
        if(a % i == 0)
            return 0;
        i+=2;
        if(a % i == 0)
            return 0;
    }
    return 1;
}

/** MAIN **/
int main()
{
    int temp = 5,count = 2;
    long long sum = 5;
    while(1)
    {
        if(temp >= 2000000)
            break;
        if(isPrime(temp))
        {
            sum+=temp;
            count++;
        }
        temp+=2;
        if(temp >= 2000000)
            break;
        if(isPrime(temp))
        {
            sum+=temp;
            count++;
        }
        temp+=4;
    }
    printf("sum is: %lld \nnumber of primes: %d\n",sum, count);
    return(0);
}