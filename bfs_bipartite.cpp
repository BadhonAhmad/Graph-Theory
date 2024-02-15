#include <bits/stdc++.h>
using namespace std;
const int N = 1e2+10;

vector<vector<int>> adj(N);
vector<int> color(N, -1);

bool bfs(int src){
    color[src] =  0;
    queue<int> q;
    q.push(src);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for(auto it : adj[node]){
            if(color[it] == -1){
                color[it] = !color[node];//if not colored , give color of the opposite of the node
                q.push(it);
            }//if color of adj is same then it is not bipartite 
            else if(color[it] == color[node]){
                return false;
            }
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

    bool isBipartite = bfs(1);

    if(isBipartite){
        cout << "GRaph is bipartite";
    }
    else{
        cout << "Graph is not bipartite";
    }
}