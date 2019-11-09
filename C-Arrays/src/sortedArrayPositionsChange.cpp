/*
OVERVIEW: In a given ascending sorted array, two numbers are changed their position, please fix those two numbers.
E.g.: In [10, 40, 30, 20, 50] 20 and 40 are swapped, so final output will be [10, 20, 30, 40, 50]

INPUTS: Ascending sorted array with two positions swapped, length of the array.

OUTPUT: Update sorted array by fixing swapped numbers.

ERROR CASES: Return NULL for invalid Inputs.

Problem Code :SAP
*/

#include <stdio.h>

void * sortedArrayPositionsChange(int *Arr, int len)
{
	if(Arr==NULL||len<1)
	return NULL;
	int f, s;
	f = s = -1;
	for (int i = 0;i < len - 1;i++) {
		if (f == -1 && Arr[i] > Arr[i + 1]) {
			f = i;
		}
		else if (f != -1 && Arr[i] > Arr[i + 1]) {
			s = i+1;
		}
	}
	int t = Arr[f];
	Arr[f] = Arr[s];
	Arr[s] = t;
}