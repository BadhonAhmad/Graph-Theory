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
int ar[]={0, 0, 1, -1};
int ra[]={1, -1, 0, 0};
vector<string> s;
int vis[25][25];
int n, m;
bool valid(int p,int q){
    if(p>=0 && p<n && q>=0 && q<m && s[p][q] !='#' && !vis[p][q] )
        return true;
        return false;
}
int cnt=0;
void dfs(int a,int b){
    cnt++;
    vis[a][b] = 1;
    for (int i = 0; i < 4; i++)
    {
        int n = a + ar[i];
        int m = b + ra[i];
        if(valid(n,bb))
            dfs(aa, bb);
    }
}
int32_t main()
{
    int tc, f = 0, sum = 0, ans = 0, t, x, y, z, i, j, cs, k, a, b, c;
    cin >> tc;
    cs=1;
    while (tc--)
    {

        cin >> n >> m;

        memset(vis, 0, sizeof(vis));
        s.clear();
        for ( i = 0; i < m; i++)
        {
            string sk;
            cin >> sk;
            s.pb(sk);
        }
        for ( i = 0; i < m; i++)
        {
            for ( j = 0; j < n; j++)
            {
                if(s[i][j] == '@'){
                    dfs(i, j);
                    break;
                }
            }
        }
        cout << cnt << e;
    }
    return 0;
}

