#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;
const int INF = 1000000000;
vector<pair<int, int>> adj[N];

int n;
void dijkstra(int s, vector<int> &dist, vector<int> &p)
{
    dist.assign(N, INF);
    p.assign(N, -1);
    set<pair<int, int>> st;
    st.insert({0, s});
    dist[s] = 0;
    while (!st.empty())
    {
        int v = st.begin()->second;
        st.erase(st.begin());
        for (auto edge : adj[v])
        {
            int to = edge.first;
            int len = edge.second;
            if (dist[v] + len < dist[to])
            {
                st.erase({dist[to], to}); // deleting the previous node as the
                                      // the node is updated now.
                dist[to] = dist[v] + len;
                p[to] = v;
                st.insert({dist[to], to}); // Inserting the updated vertion of this
                                       //  node.
            }
        }
    }
}
vector<int> restore_path(int s, int t, vector<int> &p)
{
    vector<int> path;
    for (int v = t; v != s; v = p[v])
        path.push_back(v);
    path.push_back(s);
    reverse(path.begin(), path.end());
    return path;
}
int32_t main()
{

    cin >> n;
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
    }
    vector<int> d, p;
    dijkstra(0, d, p);
    for (int i = 0; i < n; i++)
        cout << d[i] << " ";
    cout << endl;
    vector<int> path = restore_path(0, 5, p);
    for (int i = 0; i < path.size(); i++)
        cout << path[i] << " ";
    cout << endl;
    return 0;
}
