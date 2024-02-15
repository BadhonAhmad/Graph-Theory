#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector< vector<int>> adj(N);
vector<int> vis(N, 0),pathVis(N, 0);

bool dfs(int src){
    vis[src] = 1;
    pathVis[src] = 1;
    for(auto it : adj[src]){
        if(!vis[it]){
            if(dfs(it)){
                return true;
            }
        }
        else if(pathVis[it]){
            return true;//it is in the same path as it is already visited in the path
        }
    }//make the pathVis as before as the dfs is returning
    pathVis[src] = 0;
    return false;
}


int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    bool cycle = false;
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            if(dfs(i)){
                cycle = true;
                break;
            }
        }
    }

    if(cycle){
        cout << "Cycle found";
    }else{
        cout <<"NO cycles are there";
    }
}