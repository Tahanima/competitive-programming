/*
 * Problem link: https://open.kattis.com/problems/beekeeper
*/

#include <bits/stdc++.h>
using namespace std;

int n;

int check(string word, char ch){
	int cnt = 0, sz = word.size();
	for(int i = 1; i < sz; i++){
		if(word[i - 1] == word[i] && word[i] == ch) cnt++;
	}
	return cnt;
}

int get_double_vowel_count(string word){
	int Ans = check(word, 'a');
	Ans += check(word, 'e');
	Ans += check(word, 'i');
	Ans += check(word, 'o');
	Ans += check(word, 'u');
	Ans += check(word, 'y');
	return Ans;
}

void solve(){
	int mx = -1;
	string word, mx_word;
	
	for(int i = 0; i < n; i++){
		cin >> word;
		int cnt = get_double_vowel_count(word);
		if(cnt > mx){
			mx = cnt; 
			mx_word = word;
		}
	}
	
	cout << mx_word << endl;
}

int main() {
	for(; scanf("%d", &n) == 1 && n ; solve());
	return 0;
}
