#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;     cin>>n;
    int target; cin>>target;
    vector<int> a(n);
    for (auto &i : a)
    {
        cin>>i;
    }
    sort(a.begin(),a.end());
    cout<<"the array is :"<<endl;
    for (auto &i : a)
    {
        cout<<i<<" ";
    }
    
   bool found=false;
    for (size_t i = 0; i < n; i++)
    { 
        int lo=i+1,hi=n-1;
        while (lo<hi)
        {
            int cur=a[i]+a[hi]+a[lo];
            if(cur == target)    found=true;
            if(cur < target){
                lo++;
            }
            else{
                hi--;
            }
        }
    }
    if(found){
        cout<<"true"<<endl;
    }
    else cout<<"False"<<endl;
}