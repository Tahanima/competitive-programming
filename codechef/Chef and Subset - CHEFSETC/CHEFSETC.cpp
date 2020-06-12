/*
 * Problem Link: https://www.codechef.com/problems/CHEFSETC
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 4;
int Arr[N];

bool solve(){
 for(int mask = 1; mask < (1 << N); mask++){
  int sum = 0;
  for(int pos = 0; pos < N; pos++){
   if(mask & (1 << pos)) sum += Arr[pos];
  }
  
  if(sum == 0) return true;
 }
 return false;
}

int main() {
 int t;
 scanf("%d", &t);
 
 for(int i = 1; i <= t; i++){
  scanf("%d %d %d %d", &Arr[0], &Arr[1], &Arr[2], &Arr[3]);
  (solve()) ? printf("Yes\n") : printf("No\n");
 }
 return 0;
}
