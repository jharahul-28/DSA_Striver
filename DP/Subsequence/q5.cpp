class Solution {
  public:
    int count(int ind, int n, int sum, vector<int>& arr, vector<vector<int>>& dp){
        if(ind>=n) return sum==0;
        if(dp[ind][sum]!=-1) return dp[ind][sum];
        int notTake= count(ind+1, n, sum, arr, dp);
        int take=0;
        if(sum>=arr[ind]) take= count(ind+1, n, sum-arr[ind], arr, dp);
        return dp[ind][sum]=(take+notTake)%(1000000007);
    }
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        int totSum=0;
        for(int i=0;i<n;i++) totSum+=arr[i];
        int sum=(totSum-d)/2;
        if((totSum-d)%2 || totSum<d) return 0;
        vector<vector<int>> dp(n, vector<int> (totSum+1, -1));
        return count(0,n,sum, arr, dp);
    }
};