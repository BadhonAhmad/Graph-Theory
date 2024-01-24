/**Everyone who is taken by death asks for more time, while 
everyone who has time makes excuses for procrastination.
--Ali Ibn Abi Talib(Ra)**/


#include <bits/stdc++.h>
using namespace std;

#define int long long
#define N 100005

bitset<N> vis;
int indeg[N];
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,m,a,b,t;
    cin >> n >> m;
    vector<vector<int>>adj(n);
    memset(indeg, 0, sizeof(indeg));

    for(int i = 0; i < m; i++){
        cin >> a >> b;
        a--,b--;
        adj[a].push_back(b);
        indeg[b]++;
    }
    vector<int> path;
    priority_queue<int, vector<int>,greater<int>> pq;
    for(int i = 0; i < n; i++){
        if(indeg[i] == 0){
            pq.push(i);
            vis[i] = true;
        }
    }
    while (!pq.empty())
    {
        t = pq.top();
        pq.pop();
        path.push_back(t);
        for(int v : adj[t]){
            if(--indeg[v] == 0){
                vis[v] = true;
                pq.push(v);
            }
        }
    }
    if(path.size() != n) cout << "Sandro fails.\n";
    else{
        for(int i = 0; i < n; i++){
            cout << path[i] + 1<< ' ';
        }
        cout << '\n';
    }
    return 0;
}
