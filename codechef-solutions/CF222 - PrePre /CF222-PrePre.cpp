/**
 * Problem link: https://www.codechef.com/problems/CF222
**/

#include <bits/stdc++.h>
using namespace std;

string S, T;

int solve(){
	int Ans = 0, sz_S = S.size(), sz_T = T.size();
	int point_S = 0, point_T = 0;
	
	for(; point_S < sz_S && point_T < sz_T;){
		if(S[point_S] == T[point_T]){
			Ans++, point_S++;
		}
		point_T++;
	}
	return Ans;
}

int main() {
	cin >> S >> T;
	printf("%d\n", solve());
	return 0;
}
