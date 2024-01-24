#include <bits/stdc++.h>
#define fastio  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define vll vector<ll>
#define all(a) a.begin(), a.end()
#define pb(a) push_back(a)
#define e "\n"
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define cy cout<<"Case "<<cs++<<": "<<"YES"<<endl
#define ca cout<<"Case "<<cs++<<": "<<ans<<endl
#define cn cout<<"Case "<<cs++<<": "<<"NO"<<endl
const ll N=2e5+10;
using namespace std;

int main()
{
    fastio;
    ll cnt = 0,tc, f = 0, sum = 0, ans = 0, t,x, y, z, i, j,cs, k, a, b, c, n, m;
    cin >> tc;
    cs=1;
    while (tc--)
    {  
        cin >> n;
        string s;
        cin >> s;
        cnt = 0;
        for (size_t i = 0; i < s.size(); i++)
        {
            if(s[i] == 'L')
                cnt++;
        }
        if(cnt == 0 || cnt == n){
            cout << -1 << e;
            continue;
        }
        for (size_t i = 0; i < n-1; i++)
        {
            /* code */
            if(s[i] == 'L' && s[i+1] == 'R'){
                cout << i + 1 << e;
                break;
            }
            else if(s[i] == 'R' && s[i+1] == 'L'){
                cout << 0 << e;
                break;
            }
        }
        
        
    }
    return 0;
}

