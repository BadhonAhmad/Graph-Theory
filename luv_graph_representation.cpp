#include<bits/stdc++.h>
using namespace std;
int graph1[10000][10000];
vector<pair<int,int>> graph2[10000];
int main()
{
    int n,m;
    cin>>n>>m;
    for (size_t i = 1; i <= m; i++)
    {
        int v1,v2,wt;
        cin>>v1>>v2>>wt;
        graph1[v1][v2]=1;
        
        graph2[v1].push_back({v2,wt});
        graph2[v2].push_back({v1,wt});
    }                               
    for (size_t i = 1; i <= n; i++)
    {           
        for (size_t j = 1; j <= n; j++)
        {
            cout<<graph1[i][j]<<" ";
        }
        cout<<endl;
    }
}