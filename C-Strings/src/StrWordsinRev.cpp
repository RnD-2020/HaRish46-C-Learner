/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h>
void reverseStr(char *str, int f, int l) {
	char c;
	while (f <= l) {
		c = str[f];
		str[f] = str[l];
		str[l] = c;
		f++;
		l--;
	}
}
void str_words_in_rev(char *input, int len){
	int f = 0,i;
	for (i = 0;input[i] != '\0';i++) {
		if (input[i] == ' ') {
			reverseStr(input, f, i-1);
			f = i + 1;
		}
	}
	reverseStr(input, f, i - 1);
	reverseStr(input, 0, i - 1);
}
