/*
* Problem Link: https://www.codechef.com/problems/TSORT
*/

#include <bits/stdc++.h> 
using namespace std;

#define pb push_back  
#define all(v) v.begin(), v.end()
typedef vector<int> vi;


int main() {
  int t, n;
  vi arr;
  scanf("%d", &t);

  for(int i = 0; i < t; scanf("%d", &n), arr.pb(n), i++);
  sort(all(arr));
 
  for(int i = 0; i < t; printf("%d\n", arr[i]), i++);
  return 0;
}