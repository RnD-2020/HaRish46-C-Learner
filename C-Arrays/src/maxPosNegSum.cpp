
/*
OVERVIEW: Given an array of integers find the maximum possible sum formed by a positive and the negative
integer in the array.
Ex: input: [1, 9, 8, 2, 3, -1,-10,-5] output: 8 (formed by 9 and -1) 

INPUTS: An Integer array and the length of the array

OUTPUT: Maximum possible sum formed by a positive and the negative integer in the array

ERROR CASES: Return 0 for the invalid inputs

NOTES:taking sum of max from positive and negative numbers is the answer.
*/

#include <stdio.h>
#include<stdlib.h>
int maxPosNegSum(int* input,int length)
{
	if (length < 1)return 0;
	int max, min;
	max = -1; 
	min = INT_MIN; 
	for (int i = 0;i < length;i++) {
		if (input[i]>=0 && max < input[i])
			max = input[i];
		if (input[i]<0 &&input[i]>min)
			min = input[i];
	}
	if (max==-1||min==INT_MIN)return 0;
	return max+min;
}