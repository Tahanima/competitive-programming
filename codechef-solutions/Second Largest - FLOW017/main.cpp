/*
* Problem Link: https://www.codechef.com/problems/FLOW017
*/

#include <bits/stdc++.h> 
using namespace std;

int main() {
  int t, a[3];
  scanf("%d", &t);
  for(int i = 0; i < t; scanf("%d %d %d", &a[0], &a[1], &a[2]), sort(a, a + 3), printf("%d\n", a[1]), i++);
  return 0;
}