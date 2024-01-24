#include <bits/stdc++.h>
#define fastio  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define ull unsigned long long
#define ld long double
#define vll vector<ll>
#define all(a) a.begin(), a.end()
#define pb(a) push_back(a)
#define e "\n"
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
const ll N=1e5+10;
using namespace std;

int main()
{
    fastio;
    int tc;
    ll cnt = 0, f = 0, sum = 0, ans = 0, t,x, y, z, i, j, k, a, b, c, n, m;
    cin >> tc;
    while (tc--)
    {  
        cin >> n>>x>>c;
        vll v(n);
        sum = 0;
        int z = x - c;

        for (size_t i = 0; i < n; i++)
        {
            cin >> v[i];
            if(z>v[i]){
                sum += z;
                continue;
            }
            sum += v[i];
        }
        if(z == 0){
            cout << sum << e;
        }
        else {
            cout << sum << endl;
        }
    }
    return 0;
}

