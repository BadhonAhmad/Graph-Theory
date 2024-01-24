#include <bits/stdc++.h>
#define int long long
#define vll vector<int>
#define all(a) a.begin(), a.end()
#define pb(a) push_back(a)
#define e "\n"
#define inf 1e9+10
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define cy cout<<"Case "<<cs++<<": "<<"YES"<<endl
#define ca cout<<"Case "<<cs++<<": "<<ans<<endl
#define cn cout<<"Case "<<cs++<<": "<<"NO"<<endl
const int N=2e5+10;
using namespace std;
/**********************************************************************/
vector<int> g[N];
vector<int> dist(N, inf);
vector<int> vis(N, 0);
void bfs(int node){
    queue<int> q;
    q.push(node);
    vis[node] = 1;
    dist[node] = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for(auto child:g[u]){
            q.push(child);
            dist[child] = dist[u] + 1;
            vis[node] = 1;
        }
    }
}
/******************************************************************/
vector<vector<int>> va;
vector<int> ans;

bool dfs(int source,int par){
    vis[source] = 1;
    //ans.pb(source);
    bool isloop = false;
    for(auto child:g[source]){
        if(vis[child] && child == par) continue;
        if(vis[child])
            return true;
        isloop|=dfs(child,source);
        vis[child] = 1;
    }
    // ekhan theke return houa node gulo k kaj korbo
    // ans.pb(source);
    return isloop;
}
int32_t main()
{
    int cnt = 0,tc, f = 0, sum = 0, t,x, y, z, i, j,cs, k, a, b, c, n, m;
    cin >> n >> m;
    for ( i = 0; i < m; i++)
    {
        cin >> x >> y;
        g[x].pb(y);
    }
    bool isloop = false;
    for ( i = 1; i <= n; i++)
    {
        if(vis[i]) continue;
        if(dfs(i,0)){
        isloop = true;
        break;
        }
    }
    cout << isloop << e;
    return 0;
}

