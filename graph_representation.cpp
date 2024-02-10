#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int adjMat [n + 1][m + 1];
    for(int i = 0; i < n; i++){
        int u, v;
        cin >> u >> v;
        //if weight is given there will be wt instead of 1
        adjMat[u][v] = 1;
        adjMat[v][u] = 1;
    }

    vector <int> adjList[n + 1];
    vector <pair<int,int>> weightedAdjList[n + 1];
    for(int i = 0; i < n; i++){
        int u, v , wt;
        cin >> u >> v >> wt;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
        weightedAdjList[u].push_back({v, wt});
        weightedAdjList[v].push_back({u, wt});
    }

}