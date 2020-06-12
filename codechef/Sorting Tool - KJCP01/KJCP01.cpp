/*
* Problem link: https://www.codechef.com/problems/KJCP01
*/

#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
const int MX = 1e3 + 5;
piii Arr[MX];

bool cmp(piii a, piii b){
	return a.s.f == b.s.f ? a.s.s < b.s.s: a.s.f > b.s.f;
}

int main() {
	int n, m, num, cnt, st;
	map<int, pii> mp;
	scanf("%d %d", &n, &m);
    
    for(int i = 0; i < n; i++){
    	scanf("%d", &num);
    	if(!mp.count(num)) {
    		mp[num].f = 0;
    		mp[num].s = i;
    	}
    	mp[num].f++;
    	Arr[i] = piii(num, pii(0, 0));
    }
    
    for(int i = 0; i < n; i++){
    	num = Arr[i].f;
    	cnt = mp[num].f;
    	st = mp[num].s;
    	Arr[i] = piii(num, pii(cnt, st));
    }
    
    sort(Arr, Arr + n, cmp);
    for(int i = 0; i < n; i++){
    	if(i) printf(" ");
    	printf("%d", Arr[i].f);
    }
    printf("\n");
	return 0;
}
