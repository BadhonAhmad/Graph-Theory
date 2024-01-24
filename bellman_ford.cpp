#include<bits/stdc++.h>
using namespace std;
#define sz 1000
#define inf (1<<28)
int par[sz], cost[sz];
vector<int> adj[sz], w[sz];
int bellmanford(int st,int en,int n){
    cost[st] = 0;
    for (int k = 1; k < n; k++)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < adj[i].size(); j++)
            {
                if (cost[i] + w[i][j] < cost[adj[i][j]])
                {
                    cost[adj[i][j]] = cost[i] + w[i][j];
                    par[adj[i][j]] = i;
                }
            }
    }
    for (int i = 0; i < n; i++)
            for (int j = 0; j < adj[i].size(); j++)
            {
                if (cost[i] + w[i][j] < cost[adj[i][j]])
                {
                    cout << "Negative cycle detected" << endl;
                    return -inf;
                }
            }
     return cost[en];
}
void init(int n)
{
    for (int i = 0; i<n; i++)
        par[i]=-1, cost[i] = inf;
}

int main()
{
    int x, y, z, n, m, st, en;
    cin >> n >> m;
    init(n);

    for (int i = 0; i<m; i++)
    {
        cin >> x >> y >> z;
        adj[x].push_back(y);
        w[x].push_back(z);   
    }

    cin >> st >> en; 
    x =bellmanford(st,en,n);
    if(x == -inf){
        return 0;
    }
    cout << "The minimum path cost from " << st << " to " << en << " is " << x << endl;
    x = en;
    vector<int>res;
    while(~x){
        res.push_back(x);
        x = par[x];
    }

    reverse(res.begin(),res.end());
    cout << "The path: ";

    for (int i = 0; i<res.size(); i++)
        cout << res[i] << ",\n"[i==res.size()-1];
    return 0;
}