/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>

int reverse(int n) {
	int ans = 0;
	if (n < 0)n = -(n);
	while (n) {
		ans = ans * 10 + n % 10;
		n /= 10;
	}
	return ans;
}
void copy(char *str, int round,int *p) {
	while (round) {
		str[*p] = (round % 10) + '0';
		*p += 1;
		round /= 10;
	}
}
void number_to_str(float number, char *str,int afterdecimal){

	int p = 0;
	if (number < 0)str[p++] = '-';
	int round = reverse((int)number);
	copy(str, round, &p);
	if (afterdecimal == 0) {
		str[p] = '\0';
		return;
	}
	str[p++] = '.';
	number -= (int)number;
	for (int i = 0;i < afterdecimal;i++)number *= 10;
	round = reverse((int)number);
	copy(str, round, &p);
	str[p] = '\0';
}
