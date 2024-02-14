#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
vector<vector<int>> adj(N);
bool vis[N] = {0};

bool detect(int src, int p){
    vis[src] = 1;
    queue<pair <int,int>> q;
    q.push({src,p});
    while (!q.empty())
    {
        int node = q.front().first;
        int par = q.front().second;
        q.pop();
        for(auto child : adj[node]){
            if(!vis[child]){
                vis[child] = 1;
                q.push({child, node});
            }
            else if(child != par){
                return true;
            }
        }
    }
    
    return false;
}

int main()
{
    int i, n, m;
    cin >> n >> m;
    for(i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bool ans = detect(1,-1);
    if(ans){
        cout << "Cycle found\n";
    }
    else {
        cout << "NO cycle detected\n";
    }
}