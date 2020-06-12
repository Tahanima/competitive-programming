/*
 * Problem link: https://www.codechef.com/problems/CIELAB
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int A, B, rem, ans;
	cin >> A >> B;
	ans = A - B;
	rem = ans % 10;
	rem++; rem %= 10;
	ans /= 10;
	ans = ans * 10 + rem;
	if (ans == 0) ans++;
	cout << ans << endl;
	return 0;
}
