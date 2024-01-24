#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 1000000007;

vector<int> v(50005, 0), primes;

void sieve()
{
    int l = sqrt(50000);
    for (int i = 3; i <= l; i += 2)
    {
        if (v[i] == 0)
        {
            for (int j = i * i; j <= 50000; j += i)
            {
                v[j] = 1;
            }
        }
    }
    primes.push_back(2);
    for (int i = 3; i <= 50000; i += 2)
    {
        if (!(v[i]))
            primes.push_back(i);
    }
    return;
}

int main()
{
    sieve();
    int t;
    cin >> t;
    while (t--)
    {
        ll n, ans = 1;
        cin >> n;
        for (int i = 0; i < primes.size() and primes[i] <= n; i++)
        {
            ll c = n, cnt = 0;
            while (c)
            {
                cnt += c / primes[i];
                c /= primes[i];
            }
            ans = ((ans%N)*((cnt + 1)%N))%N;
        }
        cout << ans << endl;
    }
}
