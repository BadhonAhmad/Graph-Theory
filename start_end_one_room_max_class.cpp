#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int32_t main()
{
    int n;
    vector<pair<int, int>> vp = {{11, 9}, {13, 10}, {15, 14}, {18, 16}, {14, 12}, {18, 15}, {16, 13}, {13, 11}};
    sort(vp.begin(), vp.end());
    int prev_end = 0, st = 0, ans = 0;
    for (int i = 0; i < vp.size(); i++)
    {
        int en = vp[i].first;
        st = vp[i].second;
        if(st<prev_end) continue;
        /*
        |-----|
           |-----|
        */
        ans++;
        prev_end = en;
    }
    cout << ans << endl;
}