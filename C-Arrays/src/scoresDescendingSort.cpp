/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that sorts these scores in descending order.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40).
Output for this will be [ { "stud3", 40 }, { "stud2", 30 }, { "stud1", 20 } ]

INPUTS: Array of structures of type student, length of array.

OUTPUT: Sort the array in descending order of scores.

ERROR CASES: Return NULL for invalid Inputs.

Problem Code :SD
*/

#include <stdio.h>
#include<string.h>
using namespace std;

struct student {
	char name[10];
	int score;
};
void swapStudents(struct student *student1,struct student *student2){
	if(student1==NULL||student2==NULL)return;
	struct student s;
	s.score = (student1)->score;
	strcpy(s.name, (student1)->name);
	(student1)->score = (student2)->score;
	strcpy((student1)->name, (student2)->name);
	(student2)->score = s.score;
	strcpy( (student2)->name, s.name );
}
void * scoresDescendingSort(struct student *students, int len) {
	if (students==NULL||len < 1)return NULL;
	
	for(int j=len-1;j>=0;j--)
		for(int i=0;i<j;i++)
			if ((students + i)->score < (students + (i + 1))->score) {
				swapStudents((students + i),(students + (i+1));
			}
	//return ;
}
