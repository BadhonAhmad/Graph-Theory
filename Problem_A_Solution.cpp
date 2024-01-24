#include <bits/stdc++.h>
using namespace std;
vector<int> g[10000];
int depth[10000], height[10000];
int dfs(int vertex, int par = 1)
{
    for (int child : g[vertex])
    {
        if (child == par)
            continue;
        dfs(child, vertex);
        height[vertex] = max(height[vertex], height[child] + 1);
    }

    int ans = height[1] + 1;
    return ans;
}
int main()
{
    int nn, t;
    cin >> t;
    while (t--)
    {
        cin >> nn;
        for (int i = 0; i < nn - 1; i++)
        {
            int x, y;
            cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        int ans = dfs(1);
        int mangoes = (ans + 1) / 2;
        mangoes *= mangoes;
        cout << mangoes << endl;
        memset(height, 0, sizeof(height));
        memset(depth, 0, sizeof(depth));
        for (size_t i = 0; i < 100; i++)
        {
            g[i].clear();
        }
    }
    return 0;
}