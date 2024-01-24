#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 1e5;
ll parent[N];



ll find_parent(ll a)
{
    if(parent[a]==a)return a;
    parent[a]=find_parent(parent[a]);
    return parent[a];
}
void unin(ll a, ll b)
{
  ll x=find_parent(a), y=find_parent(b);
  ll par=min(x, y);
  parent[a]=par, parent[b]=par;
}


vector<pair<int,int>>g[N];
int n,m;
void krushkal()
{
    cin>>n>>m;
    priority_queue<pair<int,pair<int,int>>>pq;

    for(int i = 1 ; i <= n ;i++) parent[i] = i;

    for(int i = 0 ; i < m ; i ++){
        int x,y,wt;
        cin>>x>>y>>wt;
        pq.push({wt * -1,{x,y}});
    }
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        int wt = it.first;
        int x = it.second.first;
        int y = it.second.second;

        int a = find_parent(x);
        int b = find_parent(y);

        

        if(a == b) continue;
        unin(a,b);
        g[x].push_back({y,wt*-1});
        g[y].push_back({x,wt*-1});

    }

    return;
}


int32_t main()
{
    krushkal();
  
    for(ll i=1; i<=n; i++)
    {
        for(auto &it: g[i])
        {
            cout<<i<<" "<<it.first<<" "<<it.second<<endl;
        }
    }
}