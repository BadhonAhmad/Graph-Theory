/*
 بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم
 "In the name of Allah, the Most Gracious, the Most Merciful".

 لَا إِلَٰهَ إِلَّا اللَّٰهُ مُحَمَّدٌ رَسُولُ اللَّٰهِ
"There is no God but Allah, and Muhammad (PBUH) is the messenger of Allah."

##SALAH is the first thing you will be questioned about,
so donot make it the last thing on your mind.##

**He said, I only complain of my suffering and my grief to Allah, and
I know from Allah that which you do not know.**[Qur’an 12:86]

##And We will surely test you with something of fear and hunger and a loss of wealth and
lives and fruits, but give good tidings to the patient.##[Qur’an 2:155]

#*So whoever does righteous deeds while he is a believer – no denial will
there be for his effort, and indeed We, of it, are recorders.*#[Qur’an 21:94]
**/
#include <bits/stdc++.h>
#define fastio  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define ull unsigned long long
#define ld long double
#define vll vector<ll>
#define all(a) a.begin(), a.end()
#define pb(a) push_back(a)
#define e "\n"
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
const ll N = 1e5 + 10;
using namespace std;
vll g[N];
bool vis[N];
vector<vector<int>> cc;
vector<int> cur_cc;
int ct;
int dfs(int vertex){
    vis[vertex] = true;
    cur_cc.pb(vertex);
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
    fastio;
    int tc;
    ll cnt = 0, f = 0, sum = 0, ans = 0, t,x, y, z, i, j, k, a, b, c, n, m;
    cin >> tc >> z;
    for (int i = 0; i < z; i++)
    {
        cin >> a >> b;
        
        g[a].pb(b);
        g[b].pb(a);
    }
    for (int i = 1; i <= tc; i++)
    {
        if(vis[i]) continue;
        cur_cc.clear();
        dfs(i);
        cc.pb(cur_cc);
        cnt++;
    }
   cout << cc.size()<<e;
//    for (auto iccha: cc)
//    {
//         for (auto jaiccha:iccha)
//         {
//             cout << jaiccha << " ";
//         }
//         cout << e;
//    }
   
    return 0;
}

//[All] praise is [due] to Allah, Lord of the worlds##[Qur’an 1:1]
