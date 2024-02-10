#include <bits/stdc++.h>
using namespace std;

const int N = 100000;

vector <int> adjList[N];
vector <int> vis(N,0);
vector <vector <int>> path;
vector <int> cc;

void dfs(int u){
    vis[u] = 1;
    cc.push_back(u);
    for(auto child : adjList[u]){
        if(vis[child]) continue;
        vis[child] = 1;
        dfs(child);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v ;
        cin >> u >> v ;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            cc.clear();
            dfs(i);
            path.push_back(cc);
        }
    }

    cout << path.size()  << '\n';
    for(auto i : path){
        for(auto j : i){
            cout << j << ' ';
        }
        cout << '\n';
    }
}