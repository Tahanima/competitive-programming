/*
* Problem Link: https://www.codechef.com/problems/HEADBOB
*/

#include <bits/stdc++.h> 
using namespace std;

const int MX = 1005;

int main() {
	int t, n;
	char obs[MX];
	scanf("%d", &t);

	for(int i = 0; i < t; i++){
		scanf("%d %s", &n, obs);
		int no_y = 0, no_i = 0;
		for(int j = 0; j < n; no_y += (obs[j] == 'Y'), no_i += (obs[j] == 'I'), j++);
		if(no_i) printf("INDIAN\n");
		else if(no_y) printf("NOT INDIAN\n");
		else printf("NOT SURE\n"); 
	}
	return 0;
}