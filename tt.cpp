#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 10;
const int inf = 1e14 + 10;

vector<pair<int, int>> g[N];
vector<int> vis(N, 0);
vector<int> dist(N, inf);
int par[N];

void dijkstra(int source, int end)
{
    
    set<pair<int, int>> st; // wt,node .. 1st
    st.insert({0, source});
    dist[source] = 0;

    while (st.size() > 0)
    {
        auto node = *st.begin();
        int v = node.second;
        int dis = node.first;

        st.erase(st.begin());
        vis[v] = 1;
        for (auto child : g[v])
        {
            int child_v = child.first;
            int wt = child.second;
            if (dist[v] + wt < dist[child_v])
            {
                dist[child_v] = dist[v] + wt;
                st.insert({dist[child_v], child_v});
                par[child_v] = v;
            }
        }
    }
    
}

signed main()
{
    int t;
    // cin >> t;
    // while (t--)
    // {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < m; i++)
        {
            int x, y, wt;
            cin >> x >> y >> wt;
            g[x].push_back({y, wt});
            g[y].push_back({x, wt});
        }
        int st = 1, end = n;
        dijkstra(st, end);
        vector<int> res;
        int x = end;
        while (x)
        {
            res.push_back(x);
            x = par[x];
        }
        reverse(res.begin(), res.end());
        if(dist[end] == inf)
            cout << -1 << endl;

      else{
            for (size_t i = 0; i < res.size(); i++)
            {
                cout << res[i] << " ";
            }
            cout << endl;
        }
   // }
}