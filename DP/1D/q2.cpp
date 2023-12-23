//memoization
int f(int n, vector<int> &heights, vector<int> &dp){
    if(n==0) return 0;
    if(dp[n]!=-1) return dp[n];
    int left= f(n-1,heights,dp)+ abs(heights[n]-heights[n-1]);
    if(n==1)return left;
    int right=f(n-2,heights,dp)+ abs(heights[n]-heights[n-2]);
    return dp[n]=min(left,right);
} 
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n+1,-1);
    return f(n-1,heights,dp);
}

//tabular
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n+1,-1);
    dp[0]=0;
    for(int i=1;i<n;i++){
        int left=dp[i-1]+abs(heights[i]-heights[i-1]);
        if (i == 1) {
          dp[i] = left;
          continue;
        }
        int right=dp[i-2]+ abs(heights[i]-heights[i-2]);
        dp[i]=min(left,right);
    }
    return dp[n-1];
}

//space optimised
#include <bits/stdc++.h>
int frogJump(int n, vector<int> &heights)
{
    int p=0;
    int p2=0;
    int c;
    for(int i=1;i<n;i++){
        int left=p+abs(heights[i]-heights[i-1]);
        if (i == 1) {
          p = left;
          continue;
        }
        int right=p2+ abs(heights[i]-heights[i-2]);
        c=min(left,right);
        p2=p;
        p=c;
    }
    return p;
}