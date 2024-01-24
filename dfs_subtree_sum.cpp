/**
 * Given q queries. q<=10^5.
 * find the sum of a subtree and even numbers
 **/

#include<iostream>
#include<vector>
using namespace std;
const int n=1e5;
vector<int> g[n];
int sub_sum[n];
int even_ct[n];

void dfs(int vertex,int par=0){
    sub_sum[vertex]+=vertex;
    if(vertex % 2 == 0){
        even_ct[vertex]++; 
    }
    for(auto child : g[vertex]){

        if(child == par) continue;
        dfs(child,vertex);

        sub_sum[vertex]+=sub_sum[child];
        even_ct[vertex]+=even_ct[child];
    }
}


int main()
{
    int x;
    cin>>x;
    for (size_t i = 0; i < x-1; i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    dfs(1);
    int q;
   // cin>>q;
    int v;
    //cin>>v;
    for(int i=1; i<= x; i++)
        cout<<sub_sum[i]<<" "<<even_ct[i]<<endl;
   
    
}
