
/*
OVERVIEW: Given a number N return all the prime numbers upto the integer N.
Ex: input: 10 output: [2,3,5,7] 

INPUTS: An Integer N

OUTPUT: Return an Array of Prime numbers until the number N(N inclusive)

ERROR CASES: Return NULL for invalid inputs

Sample Input : 10
Sample Output : An Array consisting elements {2,3,5,7}
NOTES:Using an array which has 0 in prime indexs can be generated and then return the output.

Try to think of a optimized way , and avoid unnecessary comparisons.
*/

#include <stdio.h>
#include<stdlib.h>
int* nPrime(int N)
{
	if (N <= 1)return NULL;
	int *prime = (int *)calloc(sizeof(int),N);
	
	int i = 2,j=1;
	while(i<N){
		j = 2;
		while (i*j < N) {
			prime[i*(j++)] = 1;
		}i++;
		while (prime[i] != 0 && i < N)i++;
	}
	int *ans = (int *)calloc(sizeof(int),N);
	ans[0] = 2;
	i = 3;
	j = 1;
	while (i < N) {
		if (prime[i] == 0) {
			ans[j++] = i;
		}i++;
	}
	return ans;
}