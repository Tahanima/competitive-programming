/*
* Problem Link: https://www.codechef.com/problems/FLOW009
*/

#include <bits/stdc++.h> 
using namespace std;

int main() {
	int t;
	double q, p;
	scanf("%d", &t);

	for(int i = 0; i < t; scanf("%lf %lf", &q, &p), printf("%.6lf\n",  q * p * ((q > 1000) ? 0.9 : 1.0)), i++);
	return 0;
}