#include <bits/stdc++.h>
using namespace std;

void dj(vector<pair<int, int>> adj[], vector<int> &dist, int s, int t, int n)
{

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> stk;
    stk.push({0, s});
    vector<int> vis(n + 1);
    while (!stk.empty())
    {
        auto it = stk.top();
        int nd = it.second;
        vis[nd] = 1;
        if (nd == t)
            return;
        int dis = it.first;
        stk.pop();

        for (auto it : adj[nd])
        {
            int adj = it.first;
            int egWt = it.second;

            if (dis + egWt < dist[adj])
            {

                dist[adj] = dis + egWt;
                stk.push({dist[adj], adj});
            }
        }
    }

}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m, k, s, t;
        cin >> n >> m >> k >> s >> t;


        vector<pair<int, int>> adj[n + 1];
        for (int i = 0; i < m; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
        }

        int ans = INT_MAX;
    

        for (int i = 0; i < k; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> dist(n + 1, INT_MAX);
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});

            dj(adj, dist, s, t, n);

            adj[u].pop_back();
            adj[v].pop_back();

            ans = min(ans, dist[t]);
        }
        if (ans == INT_MAX)
            ans = -1;

        cout << ans << endl;
    }
}
