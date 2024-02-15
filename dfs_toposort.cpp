#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

vector<vector<int>>adj(N);
vector<int> vis(N, 0);
stack<int> ans;

void dfs(int src){
    vis[src] = 1;
    for(auto it : adj[src]){
        if(!vis[it]){
            dfs(it);
        }
    }
    //while returning from dfs pushing this to stack
    ans.push(src);
}

int main()
{
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            dfs(i);
        }
    }

    while (!ans.empty())
    {
        cout << ans.top() << ' ';
        ans.pop();
    }
    

}