/*
 * Problem Link: https://www.codechef.com/problems/FLOW011
*/

#include <bits/stdc++.h>
using namespace std;

double solve(int basic_salary) {
    double hra = (basic_salary < 1500) ? basic_salary * 0.1 : 500;
    double da = (basic_salary < 1500) ? basic_salary * 0.9 : basic_salary * 0.98;
    return (basic_salary + hra + da);
}

int main() {
    int t, basic_salary;
    scanf("%d", &t);
    for(int i = 0; i < t; scanf("%d", &basic_salary), printf("%.2lf\n", solve(basic_salary)), i++);
    return 0;
}