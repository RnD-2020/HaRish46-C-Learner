/*
Note:
1. Read instructions for each function carefully.
2. Feel free to create new functions if needed. Give good names!
3. Check the reference links when ever given.
4. After solving the question and making corresponding test cases pass
   - reflect on where is the gap in your understanding, while solving the problem.
   - if you have to create a similar problem, how would you do/tweek it?
   - when your friends seek help, instead of explaining your logic,
     give hints to solve. Always.
*/

//
// butterfly number for the given integer
//
// e.g:
// 20  => "2002"
// -2  => "-22-"
//
// To get butterfly number for the given number 20,
// take its reversal 02 and join them to form "2002".
//



void reverse(char butterfly[],int i) {
	char temp[24];
	int i;
	for (i = 0;butterfly[i] != '\0';i++);
	int j = 0;
	while (i) {
		temp[j++] = butterfly[--i];
	}temp[j] = '\0';
	for (int j = 0;temp[j] != '\0';j++) {
		butterfly[i++] = temp[j];
	}
	butterfly[i] = '\0';
}
int lengthAndReverse(int *x,int *r){
	int l=0;
	while (*x) {
		*r *= 10;
		*r += *x % 10;
		*x = *x / 10;
		l++;
	}return l;
}
void butterflyNumber(int n, char butterfly[23]) {
	long i = 0;
	long x = n;
	if (n == 0) {
		butterfly[0] = butterfly[1] = '0';
		butterfly[2] = '\0';
		return;
	}
	long l = 0;
	if (n < 0) {
		butterfly[0] = '-';
		i++;
		x = -n;
	}
	long r = 0;
	long t=lengthAndReverse(&x,&r);
	while (r || t) {
		butterfly[i++] = '0' + (r % 10);
		r = r / 10;
		t--;
	}
	butterfly[i] = '\0';
	reverse(butterfly,i);
	
}


//
// Write a function that finds the positive integers up to 100
// that are palindromes in base b
//
// b > 1
//
// saves a list of base–10 numbers less than or equal to 100
// that are palindromic in base b.
// and return the count.
//
// e.g:
// 10 => { 1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 22, 33, 44, 55, 66, 77, 88, 99}, 18 palindromes
// 2  => { 1, 3, 5, 7, 9, 15, 17, 21, 27, 31, 33, 45, 51, 63, 65, 73, 85, 93, 99}, 19 palindromes
//
// Once you have completed this function, check this reference.
// Ref: http://www.worldofnumbers.com/nobase10.htm
//
int check(int arr[], int n) {
	for (int i = 0;i<n / 2;i++) {
		if (arr[i] != arr[n - 1 - i])return 0;
	}
	return 1;
}
int palindrome(int n, int b) {
	int x = 0;
	int i = 1;
	int a = n;
	int arr[100];
	int j = 0;
	while (i <= n) {
		i *= b;
	}
	if (i > n)i /= b;
	while (n || i) {
		arr[j++] = n / i;
		n = n%i;
		i /= b;
	}
	return check(arr, j);
}
int palindromeNumbers(int b, int numbers[]) {
	if (b > 100) {
		for (int i = 1;i <= 100;i++) {
			numbers[i - 1] = i;
		}
		return 100;

	}
	int c = 0;
	int ans = b - 1;
	for (int i = 1;i < b;i++) {
		numbers[c++] = i;
	}
	for (int i = b + 1;i <= 100;i++) {
		if (palindrome(i, b)) {//printf("bgf");
			numbers[c++] = i;
			ans++;
		}
	}
	return ans;
}

//
// Write a function that finds the closest (to n) 5 positive integers
// that are even
//
// return a sorted list of assending order even numbers (greater than zero).
//
// Note:
// In case of conflict return the smallest number.
// let us say for the 5th element, 2 numbers are at same distance from n.
// then include the smallest of the 2 numbers.
//
// e.g:
// 14  => { 8, 10, 12, 16, 18}; // 8 and 20 are at equal distance from 14, we pick 8.
// 15  => { 10, 12, 14, 16, 18}; // 10 and 20 are at equal distance from 15, we pick 10.
//
// Ref: https://en.wikipedia.org/wiki/Parity_of_zero
//
// Note: You must return only numbers which are greater than zero.
//
void closest5EvenNumbers(int n, int evens[5]) {
	int i = 0;int j;
	if (n % 2 == 0) j = n - 6;
	else j = n - 5;
		while(i < 5) {
			if (j != n&&j>0)evens[i++] = j;
			j += 2;
		}
}

//
// Write a function that finds the closest 5 positive integers
// that are palindromes in base b.
//
// b > 1
//
// return a sorted list of assending order.
//
// Note:
// 1. In case of conflict return the smallest number.
//    let us say for the 5th element, 2 numbers are at same distance from n.
//    then include the smallest of the 2 numbers.
// 2. Palindromes must be greater than zero.
//    for i = 0 to 4, palindromes[i] > 0.
//
void closest5PalindromeNumbers(int n, int b, int palindromes[5]) {
	int i = 0;
	int j = 1;
	while (i < 5) {
		if ((n - j) > 0 && palindrome(n - j, b) && i < 5) {
			palindromes[i++] = n - j;
		}
		if ((n + j) > 0 && palindrome(n + j, b) && i < 5) {
			palindromes[i++] = n + j;
		}
		
		j++;
	}
	int t;
	for(i=4;i>=0;i--)
		for (j = 0;j < i;j++) {
			if (palindromes[j] > palindromes[j + 1]) {
				t = palindromes[j];
				palindromes[j] = palindromes[j + 1];
				palindromes[j + 1] = t;
			}
		}
}
