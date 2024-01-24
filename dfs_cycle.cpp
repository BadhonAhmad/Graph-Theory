#include<iostream>
#include<vector>
using namespace std;
const int n=1e5;

vector<int> g[n];
int vis[n]; 

bool dfs(int vertex,int par){

    vis[vertex]=true;
    bool isLoopexists=false;

    for(int child: g[vertex])
    {
        if(vis[vertex] && child == par) continue;
        
        if(vis[vertex]) return true;
        
        isLoopexists |= dfs( child, vertex);
    }
    return isLoopexists;
}

int main()
{
    int v,e,i;
    cin >> v ;
    for ( i = 0; i < v; i++)
    {
        int v1,v2,wt;
        cin >> v1;
        g[i+1].push_back(v1);
    }
    bool isLoopexists=false;
    for ( i = 1; i <= v; i++)
    {
        if( vis[i] ) continue;//j vertex vis seta to r dekha lgbe na,
        
        if(dfs(i,0)){
            isLoopexists=true;
            break;
        }
    }
    cout<<isLoopexists<<endl;
}