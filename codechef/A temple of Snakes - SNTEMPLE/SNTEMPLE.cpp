/*
* Problem Link: https://www.codechef.com/SNCKPA17/problems/SNTEMPLE
*/

#include <bits/stdc++.h>
using namespace std;
 
typedef signed long long ll;
const int MX = 1e5 + 5;
ll Arr[MX];
int n;
 
bool ok(int h){
	if(h == 1) return true;
	int sz = h; 
	ll _h[sz];
	
	for(int i = 0; i < sz; _h[i] = (ll)(i + 1), i++);
	map<int,int> mp; 
    
	for(int i = 0, j = 0; i < n; i++){
		if(Arr[i] < _h[j]) j = Arr[i];
		else j++;
		
		if(j == h){
			j--;
			mp[i]++;
		}
	}
	
	for(int i = n - 1, j = 0; i >= 0; i--){
		if(Arr[i] < _h[j]) j = Arr[i];
		else j++;
		
		if(j == h - 1){
			j--;
		    if(mp.count(i - 1)) return true;
		}
	}
	return false;
}
 
int binary_search(){
	int lo = 1, hi = (n + 1)/2 + 1, mid;
	for(; hi >= lo ;){
		mid = (lo + hi)/2;
		ok(mid) ? lo = mid + 1: hi = mid - 1;
	}
	return (hi + lo)/2;
}
 
int main() {
	int t;
	scanf("%d", &t);
	for(int i = 1; i <= t; i++){
		scanf("%d", &n);
		ll sum = 0;
		for(int j = 0; j < n; scanf("%lld", &Arr[j]), sum += Arr[j], j++);
		ll m = binary_search(); 
		ll minus = m * (m + 1) - m;
		printf("%lld\n", sum - minus);
	}
	return 0;
} 
