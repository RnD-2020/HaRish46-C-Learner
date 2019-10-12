/*
Given a value n

1. return nth Fibonacci number for the function nthFibonacci(int)
	EX: 0 for n=1 and 1 for n=2


2. return nth prime number for the function nthPrime(int)
	EX: 2 for n=1 and 3 for n=2

INPUTS: single integer n

OUTPUTS: nth Fibonacci number for nthFibonacci() 
		 nth prime number for nthPrime()

ERROR CASES: return -1 for the error cases
*/

int nthFibonacci(int n)
{
	
	int a = 0, b = 1,t;
	if (n <= 0)return -1;
	if (n == 1)return n;
	for (int i = 2;i <= n;i++) {
		t = a;
		a = b;
		b = t + b;;
	}
	return a;
}

int nthPrime(int num)
{
	if (num <= 0)return -1;
	int a[2600] = { 0 };
	int i = 0, j;
	while (i < 2600) {
		j = 1;
		while (i * j < 2600) {
			a[i*j] = 1;
			j++;
		}
		i++;
		while (i < 2600 && a[i] == 0)i++;
	}
	int t = 0;i = 2;
	while (t < num) {
		if (a[i] == 0) {
			t++;
		}i++;
	}
	return i;
}