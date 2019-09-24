/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/
#include<string.h>
int convert(char *a, int n,int r) {
	int t = 0;
	for(int i=0;i<n;i++) {
		if (a[i]-'0'<0 || a[i]-'0'>9)return -1;
		t *= 10;
		t += (a[i] - '0');
	}
	if (r == 1 && t > 12)return -1;
	if (r == 2 && t > 31)return -1;
	return t;
}
int check(int a, int b, int c) {
	switch (b) {
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:if (c > 31)return 0;break;
	case 2:if ((a % 100 == 0 && a % 400 == 0) || (a % 4 == 0 && a % 100 != 0)) {
		if (c > 29)return 0;
	}
		else if (c > 28)return 0;
		break;
	
	case 4:
	case 6:
	case 9:
	case 11:if (c > 30)return 0;break;
	}
	return 1;
}
int validate(int a,int a1,int a2,int b,int b1,int b2) {
	if (check(a, a1, a2) == 0)return -1;
	if (check(b, b1, b2) == 0)return -1;
	if (a > b)return 2;
	else if (b > a)return 1;
	if (a1 > b1)return 2;
	else if (b1 > a1)return 1;
	if (a2 > b2)return 2;
	else if (b2 > a2)return 1;
	return 0;
}
int isOlder(char *dob1, char *dob2) {
	
	if (strlen(dob1) != 10 || strlen(dob2) != 10)return -1;
	int a = convert(dob1 + 6, 4,0);
	int b = convert(dob2 + 6, 4,0);
	if (a == -1 || b == -1)return -1;
	
	int a1 = convert(dob1 + 3, 2,1);
	int b1 = convert(dob2 + 3, 2,1);
	if (a1 == -1 || b1 == -1)return -1;
	
	int a2 = convert(dob1 + 0, 2,2);
	int b2 = convert(dob2 + 0, 2,2);
	if (a2 == -1 || b2 == -1)return -1;
	return validate(a, a1, a2, b, b1, b2);
	
}
