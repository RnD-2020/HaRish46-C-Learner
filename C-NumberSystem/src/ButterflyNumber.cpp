/*
Given an integer as input return it's butterfly number
for example N= 1234
then it's you have to return 12344321 as output
return -1 if it is not possible create a butterfly number for the given input
*/
#include<stdlib.h>
long long butterFlyNumber(long long N)
{
	if(N<0||N>LONG_MAX)
	return -1;
	if (N == 0)return 0;
	long long x = N;
	while (x) {
		N *= 10;
		N += x % 10;
		x /= 10;
		if (N < 0)return 0;

	}
	return N;
}