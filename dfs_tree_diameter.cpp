#include<iostream>
#include<vector>
using namespace std;
vector <int> g[10000];
int depth[10000];
void dfs(int v,int par=-1){

    for(auto child : g[v]){

        if(child == par) continue;
        depth[child]=depth[v]+1;
        dfs(child,v);
    }
}

int main()
{
    int n;
    cin>>n;
    for (size_t i = 0; i < n-1; i++)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1);
    int mx_depth=-1;
    int mx_d_node;
    for (size_t i = 1; i <= n; i++)
    {
        if(mx_depth<depth[i]){
            mx_depth=depth[i];
            mx_d_node=i;
        }
        depth[i]=0;
    }
    dfs(mx_d_node);
   // cout<<mx_d_node<<endl;
    mx_depth=-1;
    for (size_t i = 1; i <= n; i++)
    {
        if(mx_depth<depth[i]){
            mx_depth=depth[i];
        }
    }
    cout<<mx_depth<<endl;  
}