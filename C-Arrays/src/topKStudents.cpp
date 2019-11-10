/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that returns the names and scores of top K students.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40) and K value is 2.
return top 2 students [ { "stud2", 30 }, { "stud3", 40 } ]

INPUTS: array of structures of type student, length of the array, integer K.

OUTPUT: Return top K students from array. Output need not be in decreasing order of scores.

ERROR CASES: Return NULL for invalid inputs.

NOTES:Learned few points about pointers and return types errors.
Problem Code :TK
*/

#include <iostream>
#include <malloc.h>

struct student {
	char *name;
	int score;
};

struct student ** topKStudents(struct student *students, int len, int K) {
	if (len < 1 || K <= 0)return NULL;//return NULL;
	struct student s;
	s.name = (char *)malloc(sizeof(char) * 10);
	for (int j = len - 1;j > 0;j--)
		for (int i = 0;i < j;i++)
			if ((students[i].score) < students[i+1].score) {
				s = students[i];
				students[i] = students[i + 1];
				students[i + 1] = s;
			}
	struct student **ans = (struct student **)malloc(sizeof(struct student*));
	for (int i = 0;i <K;i++)ans[i] = &students[i];
	return ans;
}