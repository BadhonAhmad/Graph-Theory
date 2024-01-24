#include <bits/stdc++.h>
#define ll long long
#define vll vector<ll>
#define all(a) a.begin(), a.end()
#define pb(a) push_back(a)
#define e "\n"
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
const ll N = 2e5 + 10;

using namespace std;
vector<ll> adj[N];
ll vis[N];
int disc[N];
int low[N];
bool ap[N];
ll timer = 0;
void dfs(int node, int par)
{
    vis[node] = true;
    disc[node] = low[node] = ++timer;
    int child = 0;
    for (auto nbr : adj[node])
    {
        if (nbr == par)
            continue;
        if (!vis[nbr])
        {
            dfs(nbr, node);
            low[node] = min(low[node], low[nbr]);
            child++;
            if (low[nbr] >= disc[node] && par != -1)
            {
                ap[node] = true;
            }
        }
        else
            low[node] = min(low[node], disc[nbr]);
    }
    if (par == -1 && child > 1)
        ap[node] = true;
}
int32_t main()
{
    ll cnt = 0, tc, f = 0, sum = 0, ans = 0, t, x, y, z, i, j, k, a, b, c, n, m;
    cin >> tc;
    sum = 1;
    while (tc--)
    {
        cnt = 0;
        memset(vis, 0, sizeof(vis));
        memset(disc, -1, sizeof(disc));
        memset(low, -1, sizeof(low));
        memset(ap, false, sizeof(ap));
        cin >> n >> m;
        for (i = 0; i < m; i++)
        {
            cin >> x >> y;
            adj[x].pb(y);
            adj[y].pb(x);
        }
        int timer = 0;

        for (i = 1; i <= n; i++)
        {
            disc[i] = -1;
            low[i] = -1;
        }
        for (i = 1; i <= n; i++)
        {
            if (!vis[i])
            {
                dfs(i, -1);
            }
        }
        for (size_t i = 1; i <= n; i++)
        {
            if (ap[i])
                cnt++;
        }
        cout << "Case " << sum++ << ": " << cnt << e;
        for (size_t i = 1; i <= n; i++)
        {
            adj[i].clear();
        }
    }
    return 0;
}
