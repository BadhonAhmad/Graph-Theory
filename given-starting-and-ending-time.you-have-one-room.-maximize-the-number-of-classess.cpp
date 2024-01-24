#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{                                //end ,start             
    vector<pair<ll,ll>>interval={{11,9},{13,10},{15,14},{18,16},{14,12},{18,15},{16,13},{13,11}};// first element of pair will store ending time and second will store starting time
    ll numberOfClass=0, prev_end=0;
    sort(interval.begin(), interval.end());//sort in increasing order according to finishing time
    for(int i=0; i<interval.size(); i++)
    {
        ll en=interval[i].first, st=interval[i].second;//st=9,prev_end=0 9<0
        if(st<prev_end)continue;//starting time of the present class < ending time  of previous class then overlap 
        /* |-----|
              |--------|
        */
        
        numberOfClass++;//1
        prev_end=en;
    }
    cout<<numberOfClass<<endl;
}