#include <bits/stdc++.h>

const int N = 1e5 + 10;
using namespace std;
vector<int> g[N];
bool vis[N];
vector<vector<int>> cc;
vector<int> cur_cc;
int ct;
int dfs(int vertex){
    vis[vertex] = true;
    cur_cc.push_back(vertex);
    int par = vertex;
    for (auto child : g[vertex])
    {
        if(vis[child] ){
            continue;
        }
        dfs(child);
    }
    return 0;
}
int main()
{
    int t,x, y, m, i, j, k, a, b, c, n;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
    {
        if(vis[i]) continue;
        cur_cc.clear();
        dfs(i);
        cc.push_back(cur_cc);
    }

    cout << cc.size() << endl;
    for (auto iccha: cc)
    {
        for (auto jaiccha:iccha)
        {
            cout << jaiccha << " ";
        }
        cout << endl;
    }
   
    return 0;
}

//[All] praise is [due] to Allah, Lord of the worlds##[Qur’an 1:1]
