/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/
#include<string.h>
#include <stdio.h>
#include<stdlib.h>
#include <malloc.h>
char **seperate(char *str, int *n) {
	char **ans = (char **)malloc(sizeof(char*) * 20);
	char temp[10];
	int p1 = 0, p2 = 0;
	for (int i = 0;str[i] != '\0';i++) {
		if (str[i] != ' ') {
			temp[p1++] = str[i];
		}
		else if(p1!=0){
			temp[p1] = '\0';*n = *n + 1;
			ans[p2] = (char *)malloc(sizeof(char) * 10);
			strcpy(ans[p2++], temp);p1 = 0;
		}
	}
	if (p1 != 0) {
		temp[p1] = '\0';*n += 1;
		ans[p2] = (char *)malloc(sizeof(temp));
		strcpy(ans[p2++], temp);
	}
	return ans;
}
char ** commonWords(char *str1, char *str2) {
	if (str1 == NULL || str2 == NULL)return NULL;
	int n1, n2;
	n1 = n2 = 0;
	char **words1 = seperate(str1, &n1);
	char **words2 = seperate(str2, &n2);
	char **ans = (char **)malloc(sizeof(char*) * 20);
	int p = 0;
	for (int i = 0;i<n1;i++)
		for (int j = 0;j<n2;j++)
			if (strcmp(words1[i], words2[j]) == 0) {
				ans[p] = (char *)malloc(sizeof(char) * 10);
				strcpy(ans[p++], words1[i]);
			}
	if (p == 0)return NULL;
	return ans;
}