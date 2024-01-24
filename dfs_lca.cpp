#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
vector<int> g[N];
int par[N];


void dfs(int v, int p = -1)
{ 
    par[v] = p;
    for (auto child : g[v])
    {
        if(child == p) continue;
        dfs(child, v);              
    }
}
vector<int> path(int v)
{
    vector<int> ans;

    while (v != -1)
    {
        ans.push_back(v);
        v = par[v];
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main()
{
    int n;
    cin >> n;
    for (size_t i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    } 
    dfs(1);
   int x,y;
    cin >> x >> y;
   
    vector<int> path_v1 = path(x);
    vector<int> path_v2 = path(y);
    int mn_ln = min(path_v1.size(), path_v2.size());
    int lca=-1;
    for (size_t i = 0; i < mn_ln; i++)
    {
        if (path_v1[i] == path_v2[i])
            lca = path_v1[i];
        else
            break;
    }
    cout << lca << endl;
}