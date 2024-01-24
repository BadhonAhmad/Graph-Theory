#include <bits/stdc++.h>
#define int long long

#define all(a) a.begin(), a.end()
#define pb(a) push_back(a)
#define e "\n"
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
const int N=1e5+10;
using namespace std;
int bit[N];
void update(int i,int x,int n){
    for ( ; i <=n; i+=(i&-i))
    {
        bit[i] += x;
    }
}
int sum(int i){
    int asn = 0;
    for ( i ; i > 0; i-=(i&-i))
    {
        asn += bit[i];
    }
    return asn;
}
int32_t main()
{
    int tc;
    int cnt = 0, f = 0, ans = 0, t,x, y, z, i, j, k, a, b, c, n, m;
    string s,s1,s2;
    cin >> tc;

    for ( i = 1; i <= tc; i++)
    {
        cin >> x;
        update(i, x,tc);
    }
    cout << "this is the bit,not your input arr" << e;
    for ( i = 1; i <= tc; i++)
    {
        cout << bit[i] << " ";
    }
    cout << e;
    update(3, 4 - bit[3],tc);
    for ( i = 1; i <= tc; i++)
    {
        cout << bit[i] << " ";
    }
    cout << e;

    cout << sum(3)-sum(2-1);
    return 0;
}

