#include<bits/stdc++.h>
using namespace std;
struct Edge{
    int u, v, w;
    bool operator<(Edge const & other){
        return w < other.w;
    }
};
int parent[10000];
int find_parent(int v){
    if(parent[v] == v)
        return v;
    return parent[v] = find_parent(parent[v]);
}
void Union(int u,int v){
    int par_u = find_parent(u);
    int par_v = find_parent(v);
    if(par_u == par_v)
        return;
    parent[par_v] = par_u;
}

int main()
{
    vector<Edge> graph;
    int e;
    cin >> e;
    for (int i = 0; i < e; i++){
        Edge e;
        cin >> e.u >> e.v >> e.w;
        graph.push_back(e);
    }
    for (int i = 0; i < 10000; i++){
        parent[i] = i;
    }
    sort(graph.begin(), graph.end());
    vector<Edge> ans;
    for(auto &it:graph){
        int u = it.u, v = it.v, w = it.w;
        if(find_parent(u) == find_parent(v)){
            continue;
        }
        ans.push_back(it);
        Union(u, v);
    }
    for(auto &it:ans){
        cout << it.u << " " << it.v << " " << it.w << endl;
    }
}