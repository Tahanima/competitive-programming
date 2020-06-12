/*
 * Problem link: https://open.kattis.com/problems/haypoints
*/

#include <bits/stdc++.h>
using namespace std;

int n, m;
map<string, int> job_money;

void input(){
	string job;
	int money;
	
	scanf("%d %d", &m, &n);
	for(int i = 0; i < m; cin >> job >> money, job_money[job] = money, i++);
}

int get_sum(string line){
	string token;
	stringstream ss;
	ss << line;
	int Ans = 0;
	
	for(; ss >> token ;) if(job_money.count(token)) Ans += job_money[token];
	return Ans;
}

void query(){
	string line;
	int sum = 0;
	
	for(; getline(cin, line) && line[0] != '.' ; sum += get_sum(line));
	printf("%d\n", sum);
}

int main() {
	input();
	for(int i = 0; i < n; query(), i++);
	return 0;
}
