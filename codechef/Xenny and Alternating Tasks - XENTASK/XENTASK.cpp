/*
 * Problem link: https://www.codechef.com/problems/XENTASK 
*/

#include <bits/stdc++.h>
using namespace std;

const int MX = 1e5 + 5;
typedef signed long long ll;
ll X[MX], Y[MX];

int main() {
    int t, n;
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
    	scanf("%d", &n);
    	for(int j = 0; j < n; scanf("%lld", &X[j]), j++);
    	for(int j = 0; j < n; scanf("%lld", &Y[j]), j++);
    	
    	ll a = 0, b = 0;
    	for(int j = 0; j < n; j++){
    		if(j & 1){
    			a += X[j];
    			b += Y[j];
    		}else{
    			a += Y[j];
    			b += X[j];
    		}
    	}
    	
    	printf("%lld\n", min(a, b));
    }
	return 0;
}
