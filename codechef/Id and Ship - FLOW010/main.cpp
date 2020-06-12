/*
* Problem Link: https://www.codechef.com/problems/FLOW010
*/

#include <bits/stdc++.h> 
using namespace std;

int main() {
	int t;
	char ch[5];
	
	scanf("%d", &t);
	for(int i = 0; i < t; i++){
		scanf("%s", ch);
		if(tolower(ch[0]) == 'b') printf("BattleShip\n");
		else if(tolower(ch[0]) == 'c') printf("Cruiser\n");
		else if(tolower(ch[0]) == 'd') printf("Destroyer\n");
		else printf("Frigate\n");
	}
	return 0;
}