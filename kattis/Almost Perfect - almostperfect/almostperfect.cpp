/*
* Problem link: https://open.kattis.com/problems/almostperfect
*/

#include <bits/stdc++.h>
using namespace std;

const int MX = 1e5 + 5;
int prime[MX];
vector < int >p;

void sieve()
{
    memset(prime, 0, sizeof(prime));
    prime[0] = prime[1] = 1;
    for (int i = 3; i * i <= MX; i += 2) {
        if (!prime[i]) {
            for (int j = i * i; j < MX; prime[j] = 1, j += i + i) ;
        }
    }

    p.push_back(2);
    for (int i = 3; i < MX; i += 2) {
        if (!prime[i])
            p.push_back(i);
    }
}

void solve(int n)
{
    int Ans = 1, sz = p.size(), tmp = n;
    for (int i = 0; i < sz && p[i] * p[i] <= n; i++) {
        int _p = p[i];
        if (n % _p == 0) {
            int cnt = 0;
            for (; n % _p == 0; cnt++, n /= _p) ;
            Ans *= (pow(_p, cnt + 1) - 1) / (_p - 1);
        }
    }

    if (n > 1)
        Ans *= (pow(n, 2) - 1) / (n - 1);
    Ans -= tmp;
    int diff = abs(Ans - tmp);
    if (diff == 0)
        printf("%d perfect\n", tmp);
    else if (diff <= 2)
        printf("%d almost perfect\n", tmp);
    else
        printf("%d not perfect\n", tmp);
}

int main()
{
    int n;
    sieve();

    for (; scanf("%d", &n) == 1; solve(n)) ;
    return 0;
}
