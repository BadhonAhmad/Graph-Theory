#include<bits/stdc++.h>
using namespace std;

vector<int> findLCS(const vector<int>& arr1, const vector<int>& arr2) 
{
    int m = arr1.size();
    int n = arr2.size();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    // vector<vector<int>>dp(m+1,vector<int>(n+1,0));
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (arr1[i - 1] == arr2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    vector<int> lcs;
    int i = m, j = n; 
    while (i > 0 && j > 0) {
        if (arr1[i - 1] == arr2[j - 1]) {
            lcs.push_back(arr1[i - 1]);
            i--;
            j--;
        } 
        else if (dp[i - 1][j] > dp[i][j - 1]) i--;
        else j--;
    }
    reverse(lcs.begin(), lcs.end());
    return lcs;
}

vector<int> findLIS(const vector<int>& nums) 
{
    vector<int> sortedNums(nums);
    // sorted k return korbo vector<int>sorted(nums);
    sort(sortedNums.begin(), sortedNums.end());
    
    vector<int> lcs = findLCS(nums, sortedNums);
    return lcs;
}

int main() 
{
    vector<int> nums = {10, 22, 9, 33, 22, 34, 41, 60};
    vector<int> Lis = findLIS(nums);

    cout << "Longest Increasing Subsequence: \n";
    
    for (int num : Lis) cout << num << " ";
    
    return 0;
}
