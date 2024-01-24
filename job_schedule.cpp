#include<bits/stdc++.h>
using namespace std;
int occupied[100][100];

int main()
{
    int n;
    cin >> n;
    set<pair<int, pair<string, int>>> st;
    for (int i = 0; i < n; i++){
        string s;
        int timespan, deadlin;
        cin >> s >> timespan >> deadlin;
        st.insert({deadlin, {s, timespan}});
    }
    for(auto &it : st){
        bool if_checked = 1;
        int d = it.first - 10;
        string ss=it.second.first;
        for (int i = 0; if_checked; i++){ 
            if (ss[0] == 'T' && !occupied[i][d])
                occupied[i][d] = 1, if_checked = 0;
            if(ss[0] == 'L' && !occupied[i][d] && !occupied[i][d-1] && !occupied[i][d-2])
                occupied[i][d] = 1,occupied[i][d - 1] = 1,occupied[i][d - 2] = 1, if_checked = 0;
        }
    }
    int ans = 0;
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 7;j++){
            if(occupied[i][j])
                { ans++;
                break;}
        }
    }
    cout << ans << endl;
    return 0;
}