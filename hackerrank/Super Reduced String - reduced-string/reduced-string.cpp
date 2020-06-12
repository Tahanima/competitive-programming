/*
 * Problem link: https://www.hackerrank.com/contests/101hack36/challenges/reduced-string 
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	string S, Ans = "";
	cin >> S;
	int n = S.size();
	stack<char> ST;
	
	for(int i = 0; i < n; i++){
		if(!ST.empty()){
			if(ST.top() == S[i]) ST.pop();
			else ST.push(S[i]);
		}else{
			ST.push(S[i]);
		}
	}
	
	for(; !ST.empty() ; Ans.push_back(ST.top()),ST.pop());
	reverse(Ans.begin(), Ans.end());
	Ans.size() ? cout << Ans << endl : cout << "Empty String" << endl;
	return 0;
}
