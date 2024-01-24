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
    cin >> tc;
    string s1,s2,s3;
    while (tc--)
    {  
        ans = 0,f = 0,sum = 0;  
        cin >> n;
        j = n;
        if((n/2)%2){
            no;
            continue;
        }
        yes;
        x = 0;
        i = 1;
        while (i <= (n/2))
        {
            x += 2;
            cout << x<<" ";
            sum += x;
            i++;
        }
        x = 1;
        ans = 1;
        for (j = 1; j < (n / 2);j++){
            cout << x << " ";
            ans += x;
            x += 2;
        
        }
        cout <<sum-(ans-1), nl;
    }
    return 0;
}

