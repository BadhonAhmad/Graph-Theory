
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
const int N = 1e5 + 10;
using namespace std;

vector<int> g[N];
bool isloop = false;
bool vis[N];
bool dfs(int v,int par){
    vis[v] = true;
    for (int child:g[v])
    {
        if (vis[child] && child == par) continue;
            if (vis[child])
            {
                return true;
            }
        isloop |= dfs(child,v);
    }
    return isloop;
}
int main()
{
    fastio;
    int cnt = 0, f = 0, sum = 0, ans = 0, t,x, y, z, i, j, k, a, b, c, n, m;
    cin >> n >> m;
    for (  i = 0; i < m; i++)
    {
        cin >> a >> b;
        g[a].pb(b);
    }
    f = 0;
    for (i = 1; i <= n; i++)
    {
        if(dfs(i,0)){
            f = 1;
            break;
        }
    }
    if(f)
        cout << 1 << e;
        else
            cout << 0 << e;
        return 0;
}
