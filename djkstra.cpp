#include <bits/stdc++.h>
using namespace std;
#define sz 100010
#define inf 1e15

vector<long long> adj[sz], w[sz];
long long par[sz], cost[sz];
bool dijkstra(long long st, long long en)
{
    // 1.pq te push
   priority_queue< pair<long long,long long> ,
    vector< pair<long long,long long> >, greater< pair<long long,long long> > > pq;
    pq.push({0, st});
    cost[st] = 0;
    long long u, c;
    // 2.kaj shuru while pq ache
    while (!pq.empty())
    {
        u = pq.top().second;
        c = pq.top().first;
        if(u== en)
            return true;
        pq.pop();

        // 3.for diye tar sokol adj e jabe
        for (long long i = 0; i < adj[u].size(); i++)
        {
            if ( c + w[u][i] < cost[adj[u][i]])
            {
                cost[adj[u][i]] = c + w[u][i];
                pq.push({cost[adj[u][i]], adj[u][i]});
                par[adj[u][i]] = u;
            }
        }
    }
    return false;
}
void init(long long n)
{
    for (long long i = 0; i < n; i++)
    {
        par[i] = -1, cost[i] = inf;
    }
}
signed main()
{
    long long x, y, z, n, m;
    cin >> n >> m;
    init(n);
    for (size_t i = 0; i < m; i++)
    {
        cin >> x >> y >> z;
        x--;
        y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
        w[x].push_back(z);
        w[y].push_back(z);
    } 
    long long st=1, en=n;
   // cin >> st >> en;
   bool ans= dijkstra(st-1, en-1);
    x = en - 1;
    vector<long long> res;
    while (~x)
    {
        res.push_back(x+1);
        x = par[x];
    }
    reverse(res.begin(), res.end());
   if(ans){
    for (size_t i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
   }
   else
       cout<<-1;
}