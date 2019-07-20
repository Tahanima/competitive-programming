/*
* Problem Link: https://www.codechef.com/problems/AMR15A
*/

#include <bits/stdc++.h> 
using namespace std;

int main() {
  int t, n, even = 0, odd = 0;
  scanf("%d", &t);

  for(int i = 0; i < t; scanf("%d", &n), (n & 1) ? odd++ : even++, i++);
  (even > odd) ? printf("READY FOR BATTLE\n") : printf("NOT READY\n");
  return 0;
}