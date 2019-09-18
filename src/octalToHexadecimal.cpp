/*
OVERVIEW:
1)Write a function which takes a octal number as input and returns the hexadecimal number for 
  octalToHexadecimal().
E.g.: octalToHexadecimal(10) returns 8.

2)Write a function which takes a fractional octal number as input and returns the hexadecimal number for 
octalToHexadecimalFraction() until precision two
E.g.: octalToHexadecimal(6.01) returns 6.04

INPUTS: Single octal number num;

OUTPUT: hexadecimal value of the octal number num.

Discalimer:Return 0 for invalid cases.[Negetive Numbers]

There are no test cases for fraction method but it would be good if you complete that too.
*/
#include<stdlib.h>
#include<math.h>
int octalToHexadecimal(long int num)
{
	if (num <= 0)return 0;
	long int n = 0, i = 0, x;
	while (num) {
		x = num % 10;
		n += x*pow(8, i);
		num /= 10;i++;
	}
	int a = 0;
	while (pow(16, a++) < n);

	int b = 0;
	while (n) {
		b *= 10;
		b += n / (int)pow(16, a);
		n %= (int)pow(16, a);
		a--;
	}
	if (a == 0)b *= 10;
	return b;
}

float octalToHexadecimalFraction(float num)
{
	return 0.0;
}