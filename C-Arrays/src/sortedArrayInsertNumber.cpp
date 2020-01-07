/*
OVERVIEW: Given a sorted array, insert a given number into the array at appropriate position.
			E.g.: Arr = [2, 4, 6], num = 5 final Arr = [2, 4, 5, 6]. 5 is inserted at 2nd index.

INPUTS: Integer	Array pointer, length of the array, number to be inserted.

OUTPUT: Array pointer after inserting number.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Use memory allocation techniques to allocate memory.

ProblemCode :SAIN
*/

#include <stdio.h>
#include <malloc.h>

int * sortedArrayInsertNumber(int *Arr, int len, int num)
{
	if (len < 1 || Arr == NULL)return NULL;
	int mid = len;
	for (int i = 0;i < len - 1;i++) {
		if (Arr[i] > num) {
			mid = i;
			break;
		}
	}
	realloc(Arr, sizeof(int)*(len + 1));
	int i;
	for (i = len;i > mid;i--)
		Arr[i] = Arr[i - 1];
	Arr[i] = num;
	return Arr;
}