/*
* Problem Link: https://www.codechef.com/problems/VOWELTB
*/

#include <bits/stdc++.h> 
using namespace std;

int main() {
	char ch;
	scanf("%c", &ch);
	if(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
		printf("Vowel\n");
	else 
		printf("Consonant\n");
	return 0;
}