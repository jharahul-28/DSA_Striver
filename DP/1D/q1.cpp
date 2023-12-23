int count(vector<int> &dp, int n){
    if(n<=1) return 1;
    if(dp[n]!=-1) return dp[n];
    return dp[n]=((count(dp,n-1)%1000000007)+(count(dp,n-2)%1000000007))%1000000007;
}
int countDistinctWays(int n) {
    //  Write your code here.
    vector<int> dp(n+1,-1);
    return count(dp,n);
}