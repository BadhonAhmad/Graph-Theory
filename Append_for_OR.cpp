#include <bits/stdc++.h>
#define int long long
#define vll vector<int>
#define all(a) a.begin(), a.end()
#define pb(a) push_back(a)
#define e "\n"
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define cy cout<<"Case "<<cs++<<": "<<"YES"<<endl
#define ca cout<<"Case "<<cs++<<": "<<ans<<endl
#define cn cout<<"Case "<<cs++<<": "<<"NO"<<endl
const int N=2e5+10;
using namespace std;
/**********************************************************************/
int32_t main()
{
    int cnt = 0,tc, f = 0, sum = 0, ans = 0, t,x, y, z, i, j,cs, k, a, b, c, n, m;
    cin >> tc;
    cs=1;
    while (tc--)
    {  
        cin >> n >> m;
        sum = 0;
        for (size_t i = 0; i < n; i++)
        {
            cin >> x;
            sum |= x;
        }
        if((sum | m) != m){
            cout << -1 << e;
            continue;
        }
        if(sum == m){
            cout << 0 << e;
            continue;
        }
        x = m ^ sum;
        if(x>m){
            cout << -1 << e;
        }
        else{
            cout << x << e;
        }
    }
    return 0;
}

