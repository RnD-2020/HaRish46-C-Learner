//
// Every number repeats twice, except one number.
// Write a function that finds the number that does not repeat.
//
// e.g:
// {11, 8, 11}, 3  => 8
//
int numberWithoutRepeatition(int numbers[], int size) {
	int a[32] = { 0 };
	for(int k=0;k<32;k++)
	for (int i = 0;i < size;i++) {
		a[k] += (numbers[i] & 1 << k)?1:0;
	}
	for (int k = 0;k < 32;k++)a[k] = a[k] % 2;
	int b = 0;
	int t = 1;
	for (int k = 0;k < 32;k++) {
		b += a[k] * t;
		t *= 2;
	}
	return b;
}

//
// encode an array of numbers by doing
// XOR with n'th prime number
// and subtract 1
//
// output the encode numbers in encodedMessage[8] array.
//
// e.g:
// for 5'th prime
// encoding will be
// (message[i] ^ 11) - 1
// since 11 is the 5'th prime. // 2, 3, 5, 7, 11...
//
#include<math.h>
int isprime(int n) {
	for (int i = 2;i <= sqrt(n);i++)
		if (n%i == 0)return 0;
	return 1;
}
int nprime(int n) {
	int i = 1;
	while (n) {
		i++;
		if (isprime(i)) {
			n--;
		}
		
	}
	return i;
}
void encodeWithNthPrime(int message[8], int n, int encodedMessage[8]) {
	int x = nprime(n);
	for (int i = 0;i < 8;i++) {
		encodedMessage[i] = (message[i] ^ x) - 1;
	}
}

//
// decode an array of numbers in
// which are encoded using above encodeWithPrime function.
//
// output the decoded numbers in decodedMessage[8] array.
//
void decodeWithNthPrime(int message[8], int n, int decodedMessage[8]) {
	int x = nprime(n);
	for (int i = 0;i < 8;i++) {
		decodedMessage[i] = ((message[i]+1) ^ x) ;
	}
}

//
// Encode data and flags in packet header
//
// From Left to Right the data and flags are packed as follows:
// fromMobileId   - 7 bits
// toMobileId     - 7 bits
// msgId          - 7 bits
// msgLen         - 7 bits
// reserved       - 2 bits
// urgent         - 1 flag bit
// adHoc          - 1 flag bit
//
// Note:
// The values will be in the range
// 0 <= fromMobileId, toMobileId, msgId, msgLen <= 127
//
// The reserved bits should be set to zero.
//
// For the context refer:
// https://en.wikipedia.org/wiki/Transmission_Control_Protocol#TCP_segment_structure
//
unsigned int packHeader(int fromMobileId, int toMobileId, int msgId,
                        int msgLen, bool urgent, bool adHoc) {
	unsigned int x = 0;
	x = x|adHoc;
	x = x | urgent << 1;
	x = x | msgLen <<4;
	x = x | msgId << 11;
	x = x | toMobileId << 18;
	x = x | fromMobileId << 25;
	return x;
}

// unpack a given header, with the properties like the above
void unpackHeader(unsigned int header, int *pFromMobileId, int *pToMobileId,
                  int *pMsgId, int *pMsgLen, bool *pUrgent, bool *pAdHoc) {
	*pAdHoc = header & 1;
	*pUrgent = header & (1<<1);
	*pMsgLen = (header&(127 << 4))>>4;
	*pMsgId = (header&(127 << 11))>>11;
	*pToMobileId = (header&(127 << 18))>>18;
	*pFromMobileId = (header&(127 << 25))>>25;
}
