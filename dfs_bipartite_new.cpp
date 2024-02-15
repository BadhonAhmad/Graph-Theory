#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
vector< vector<int> > adj(N);
vector<int > color(N, -1);

bool dfs(int src,int col){
    color[src] = col;
    for(auto it : adj[src]){
        if(color[it] == -1){
            if(dfs(it, !col) == false) return false; 
        }
        else if(color[it] == col){
            return false;
        }
    }
    return true;
}

int main()
{
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bool isBipartite = true;
    for(int i = 1; i <= n; i++){
        if(color[i] == -1){
            if(dfs(i, 0) == false){
                isBipartite = false;
                break;
            }
        }
    }
    if(isBipartite){
        cout << "Yes, it is bipartite";
    }
    else{
        cout <<"Sorry it is not bipartite";
    }

}