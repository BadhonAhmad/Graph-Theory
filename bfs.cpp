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
const ll N=1e5+10;
using namespace std;
vector<int> g[N];
int vis[N];
int level[N];
void bfs(int source){
    queue<int> q;
    q.push(source);
    vis[source] = 1;
    while (!q.empty())
    {
        int cur_v = q.front();
        q.pop();
        for (auto child : g[cur_v])
        {
            if(!vis[child]){
                q.push(child);
                vis[child] = 1;
                level[child] = level[cur_v] + 1;
            }
        }
    }
}
int main()
{
    fastio;
    int tc;
    ll cnt = 0, f = 0, sum = 0, ans = 0, t,x, y, z, i, j, k, a, b, c, n, m;
    cin >> n;
    for (size_t i = 0; i < n-1; i++)
    {
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    bfs(1);
    for (size_t i = 1; i <= n; i++)
    {
        /* code */
        cout << i << ":" << level[i] << endl;
    }
    

    return 0;
}

