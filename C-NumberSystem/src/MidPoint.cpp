//fill this funtion return interger value only
//don't change the signature
#include<stdio.h>
int midPoint(int a, int b)
{
	int x = 0;
	int p = 1, n = 1;
	int c, d;
	for (int i = 0;i <31;i++) {
		c = a >> i;
		d = b >> i;
		int n= ((((c % 2 == 0) ? 0 : 1) + ((d % 2 == 0) ? 0 : 1))*p) / 2;
		if(n>0)
		x += n;
		else x -= n;
		p *= 2;
	}
	
	if (a >= 0 && b >=0 )return x;
	return -((x^-1)^(1<<31)+1);//(x ^ (-1)) + 1;//(!x) + 1;
}