#include<bits/stdc++.h>
using namespace std;
int parent[10000];
struct Edge
{
    int u, v, w;
    bool operator<(Edge const  & other){
        return w < other.w;
    }
};

int find_par(int u){
    if(parent[u] == u)
        return u;   
    return parent[u] = find_par(parent[u]);
}

void Union(int u,int v){
    int par_u = find_par(u);
    int par_v = find_par(v);
    if(par_u == par_v)
        return;
    parent[par_u] = par_v;
}

int main()
{
    int e,i;
    cin >> e;
    vector<Edge> graph;
    Edge ed;
    for(i = 1; i <= e; i++){
        cin >> ed.u >> ed.v >> ed.w;
        graph.push_back(ed);
    }
    sort(graph.begin(), graph.end());//sort kora hoy ni
    for (i = 0; i < 1000; i++){
        parent[i] = i;
    }
    vector<Edge> ans;

    for(auto &it:graph){
        int u, v, wt;
        u = it.u;
        v = it.v;
        if(find_par(u) == find_par(v)) continue;
        ans.push_back(it);
        Union(u, v);
    }
    for(auto &it:ans){
        cout << it.u << " " << it.v <<" "<< it.w<<"\n";
    }
}