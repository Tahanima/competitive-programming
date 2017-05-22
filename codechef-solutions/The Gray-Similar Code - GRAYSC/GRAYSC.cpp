/*
 * Problem Link: https://www.codechef.com/problems/GRAYSC
*/

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;
const int MX = 1e5 + 5;
int n;
ll Arr[MX];

bool solve(){
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			for(int k = j + 1; k < n; k++){
				for(int l = k + 1; l < n; l++){
					if((Arr[i]^Arr[j]^Arr[k]^Arr[l]) == 0) return true;
				}
			}
		}
	}
	return false;
}

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; scanf("%llu", &Arr[i]), i++);
	
	if(n >= 130) printf("Yes\n");
	else solve() ? printf("Yes\n") : printf("No\n");
	
	return 0;
}
