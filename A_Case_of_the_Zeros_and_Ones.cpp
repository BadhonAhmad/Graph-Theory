#include <bits/stdc++.h>
#define fastio  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define int long long
#define vll vector<int>
#define all(a) a.begin(), a.end()
#define pb(a) push_back(a)
#define nl cout<<"\n"
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define as cout << ans << "\n"
#define yn cout << (f? "YES":"NO") << "\n"
const int N=2e5+10;
using namespace std;
int32_t main()
{
    fastio;
    int ct,tc,f,sum,ans,t,x,y,z,i,j,k,a,b,c,d,n,m;
    string s1;
    ans = 0, ct = 0, f = 0, sum = 0;
    cin >> a;
    cin >> s1;
    for (i = 0; i < s1.size() - 1; i++)
    {
        if (s1[i] == '1' && s1[i + 1] == '0')
            ct++, i++;
        if (s1[i] == '0' && s1[i + 1] == '1')
            ct++, i++;
    }
        cout << s1.size() - ct * 2, nl;
 
    return 0;
}

