#include <bits/stdc++.h>

int f(int n, vector<vector<int>> &points, vector<vector<int>> &dp, int prev){
    if(n==0){
        int maxi=INT_MIN;
        for(int i=0;i<3;i++) {
            if(i!=prev)
            maxi=max(maxi, points[0][i]);
        }
        return maxi;
    }
    if (dp[n][prev]!=-1) return dp[n][prev];
    int ways= INT_MIN;
    for(int i=0;i<3;i++){
        if(i!=prev)
        ways=max(ways, points[n][i]+f(n-1,points,dp,i));
    }
    return dp[n][prev]=ways;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>> dp(n,vector<int> (4,-1));
    return f(n-1,points,dp,3);
}