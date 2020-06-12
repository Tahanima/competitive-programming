/*
 * Problem Link: https://www.codechef.com/problems/CHKSTR
*/

#include <bits/stdc++.h>
using namespace std;

typedef signed long long ll;
const int MX = 1e6 + 5;
const ll mod = 1e9 + 7;
int mx, n;
ll a, b, Arr[MX], f[MX];

void process(string line){
	n = mx = 0;
	int num;
	stringstream ss;
	ss << line;
	for(; ss >> num ;){
		Arr[n++] = num;
		mx = max(mx, num);
	}
}

ll solve(){
	f[0] = a;
	f[1] = b;
	for(int i = 2; i < mx; f[i] = ((f[i - 1] % mod) + (f[i - 2] % mod)) % mod, i++);
	ll Ans = 0;
	for(int i = 0; i < n; i++){
		Ans = ((Ans % mod) + (f[Arr[i] - 1] % mod)) % mod;
	}
	return Ans;
}

int main() {
	int t;
	string line;
	scanf("%d", &t);
	
	for(int i = 1; i <= t; i++){
		scanf("%lld %lld", &a, &b);
		getline(cin, line); 
		getline(cin, line); 
		process(line);
		printf("%lld\n", solve());
	}
	return 0;
}
