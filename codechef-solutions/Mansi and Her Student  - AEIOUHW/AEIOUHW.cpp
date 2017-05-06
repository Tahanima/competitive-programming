/*
 * Problem Link: https://www.codechef.com/problems/AEIOUHW
 * solution: no. of ways to choose consonants * no. of ways to choose vowels * arrangements for vowels & consonants
*/

#include <bits/stdc++.h>
using namespace std;

typedef signed long long ll;
ll con, vow;

ll fact(ll p, ll q){
	ll Ans = 1, num = p + q; 
	for(ll i = 2; i <= num; Ans *= i, i++);
	return Ans;
}

ll nCr (ll n, ll r){
	r = max(r, n - r);
	ll Ans = 1;
	for(ll i = 0; i < r; Ans = Ans * (n - i) / (i + 1), i++);
	return Ans;
}

void get_count(string str){
	int sz = str.size();
	con = vow = 0;
	for(int i = 0; i < sz; i++){
		if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') vow++;
        else con++;
	}
}

int main() {
	int t;
	ll p, q;
	string str;
	
	scanf("%d", &t);
	for(int i = 1; i <= t; i++){
		cin >> str;
		get_count(str);
		scanf("%lld %lld", &p, &q);
		ll Ans = nCr(con, p) * nCr(vow , q) * fact(p , q);
		printf("%lld\n", Ans);
	}
	return 0;
}
