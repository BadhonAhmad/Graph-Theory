#include <bits/stdc++.h>
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define ll long long
#define ull unsigned long long
#define ld long double
#define vll vector<ll>
#define all(a) a.begin(), a.end()
#define pb(a) push_back(a)
#define e "\n"
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
const ll N = 1e5 + 10;
using namespace std;
int vis[10000];
vector<int> adj[2000];
void dfs(int a)
{
    vis[a] = 1;
    for (auto child : adj[a])
    {
        if (vis[child])
            continue;
        dfs(child);
    }
}

int main()
{
    fastio;
    int tc;
    int cnt = 0, f, sum = 0, ans = 0, t, x, y, z, i, j, k, a, b, c, n, m;
    for (i = 0; i < 201; i++)
    {
        cin >> tc;
        if (tc == 0)
        {
            break;
        }
        cin >> n;
        memset(vis, -1, sizeof(vis));
        vector<int> adj[tc + 5];
        x = 1;
        while (n--)
        {
            cin >> y >> z;
            adj[y].pb(z);
            adj[z].pb(y);
        }
        queue<int> q;
        q.push(0);
        vis[0] = 1;
        while (!q.empty() && x)
        {
            f = q.front();
            q.pop();
            for (auto child : adj[f])
            {
                if (vis[child] == -1)
                {
                    vis[child] = !vis[f];
                    q.push(child);
                }
                else if (vis[child] == vis[f])
                {
                    x = 0;
                    break;
                }
            }
        }
        if (x)
            cout << "BICOLORABLE." << e;
        else
            cout << "NOT BICOLORABLE." << e;
    }

    return 0;
}
