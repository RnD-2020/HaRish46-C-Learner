//
//  E01_Functions.cpp
//  Unit1_exercise1_understanding_functions
//

/*
 
 Note:
 Implement the functions in this exercise file to make the tests
 pass in E01_FunctionsSpec.cpp file.
 
 */


//
// Note:
//  Think of all the edge cases.
//
// returns the mid-point of
// given 2 points on X-axis
//
using namespace std;
int midPoint(int x1, int x2) {
    return (x1+x2)/2;
}

//
// sum of most significant digits of non-negative integers.
//
int sumOfMSDs(int num1, int num2) {
	int a, b;
	a = b = 0;
	while (num1) {
		a = num1;
		num1 /= 10;
	}
	while (num2) {
		b = num2;
		num2 /= 10;
	}
    return a+b;
}

//
// sum of two 100 digit positive numbers
//
void sumOf100DigitNumbers(int num1[100], int num2[100], int sum[101]) {
	int a;
	for (int i = 0;i < 101;i++)sum[i] = 0;
	for (int i = 99;i>=0;i--) {
		a = num1[i] + num2[i]+sum[i+1];
		sum[i + 1] = a % 10;
		a /= 10;
		sum[i] = a % 10;
	}
}

//
// product of two 100 digit positive numbers
//
void productOf100DigitNumbers(int num1[100], int num2[100], int prod[200]) {
	int a = 0;
	for (int i = 0;i < 200;i++)prod[i] = 0;
	for (int i = 99;i >= 0;i--) {
		for (int j = 99;j >= 0;j--) {
			a = num1[j] * num2[i] + prod[i + j+1];
			prod[i + j+1] =(a % 10);
			a /= 10;
			prod[i+j] = prod[i + j]+(a % 10);
		}
	}
}
