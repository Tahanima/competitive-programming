/*
 * Problem Link: https://www.codechef.com/problems/TWEED
*/

#include <bits/stdc++.h>
using namespace std;

int Arr[55];

int main() {
	int t, n;
	string str;
	scanf("%d", &t);
	
	for(int i = 1; i <= t; i++){
		scanf("%d", &n);
		cin >> str;
		for(int j = 0; j < n; scanf("%d", &Arr[j]), j++);
		if(n == 1 && (Arr[0] % 2 == 0) && str == "Dee") printf("Dee\n");
		else printf("Dum\n");
	}
	return 0;
}
