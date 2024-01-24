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
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
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

void dfs(int i, int j, int initialCol, int newCol, vector<vector<int>> &image)
{
    int n = image.size(); 
    int m = image[0].size();
    if (i < 0 || j < 0)
        return;
    if (i >= n || i >= m)
        return;
    if (image[i][j] != initialCol)
        return;
    image[i][j] = newCol;
    dfs(i - 1, j,initialCol,newCol,image);
    dfs(i + 1, j,initialCol,newCol,image);
    dfs(i, j - 1,initialCol,newCol,image);
    dfs(i, j + 1,initialCol,newCol,image);
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newCol)
{

    int initialCol = image[sr][sc];
    if(initialCol != newCol)
    dfs(sr, sc, initialCol, newCol, image);
    return image;
}

//[All] praise is [due] to Allah, Lord of the worlds##[Qur’an 1:1]
