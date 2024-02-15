#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
vector<vector<int>> adj(N);
bool vis[N] = {0};

bool detect(int src, int p){
    vis[src] = 1;
    for(auto it : adj[src]){
        if(!vis[it]){
            if(detect(it, src) == true){//dfs cholte cholte kutha o jodi cycle pawa jay tahole return true sobar jonno
                return true;
            }
        }
        else if(it != p){//parent na hoye she kivabe visited hoilo, tahole take aage keu visit korse,so ekhane cycle 
            return true;
        }
    }
    return false;
}

int main()
{
    int i, n, m;
    cin >> n >> m;

    for(i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bool ans = detect(1,-1);

    if(ans){
        cout << "Cycle found\n";
    }
    else {
        cout << "NO cycle detected\n";
    }
}