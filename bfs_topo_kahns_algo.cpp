#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector< vector<int>> adj(N);
vector<int> indeg(N);
int main()
{
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        indeg[b]++;
    }

    queue<int> q;

    for(int i = 1; i <= n; i++){
        if(indeg[i] == 0){
            q.push(i);
        }
    }

    vector<int> topo;
    
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for(auto it : adj[node]){
            indeg[it]--;
            if(indeg[it] == 0){
                q.push(it);
            }
        }
    }

    for(auto i : topo){
        cout << i << ' ';
    }

}