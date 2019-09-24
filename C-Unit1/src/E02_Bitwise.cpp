//
//  E02_Bitwise.cpp
//  Unit1_exercise2_understanding_bitwise
//

/*
 
 Note:
 Implement the functions in this exercise file to make the tests
 pass in E02_BitwiseSpec.cpp file.
 
 Your primary goal is to implement all these functions by using
 bitwise operators only.
 
 */

int andOfEachByte(int n) {
	int a = 0;
	a=(n >> 24)&255;
	//return a;
	a = a & (n>>16);
	a = a & (n>>8);
	a = a&n;
	return a;
}

//
// Note1:
// implement the function using bitwise operators only
// should not use * and + operators.
int numberFromBits(int bits[32]) {
	int a = bits[0];
	for (int i = 1;i<32;i++) {
		a = a << 1 | bits[i];
	}
	return a;
}

//
// Note2:
// implement the function using bitwise operators only
// should not use % and / operators.
void bitsFromNumber(int n, int bits[32]) {
	int a = 1;
	for (int i = 31;i >= 0;i--) {
		bits[i] = 1;
	}
	for (int i = 31;i >= 0;i--) {
		bits[i] = n>>(31-i) & 1;
		a = a << 1;
	}
}

//
// Note3:
// Refer this to understand how numbers are represented in binary format
// https://www.youtube.com/watch?v=qrUjFtZZWf4
// mainly how negative number are represented.
//
// implement this function by calling above bitsFromNumber function only.
//
int numberOfOnesInBinary(int n) {
	int c = 0;
	for (int i = 0;i < 32;i++) {
		c += n >> i & 1;
	}
	return c;
}

//
// Returns
//  1 - yes
//  0 - no
//
int isPalindromeInBase256(unsigned long int n) {
	unsigned long int a = 0;
	
		a = (a <<8 ) | ((n >> 0)&255);
		a = (a << 8) | ((n >> 8) & 255);
		a = (a << 8) | ((n >> 16) & 255);
		a = (a << 8) | ((n >> 24) & 255);
	//return a;
		while ((a & 1) == 0)
		a = a >> 1;
	while ((n & 1) == 0)n = n >> 1;
	return (a == n) ? 1 : 0;
	return a;
}
