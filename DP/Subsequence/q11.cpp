//memo
class Solution{
  public:
    int f(int i, int price[], int t, vector<vector<int>>& dp){
        if(t<=0) return 0;
        if(dp[i][t]!=-1) return dp[i][t];
        if(i==0) {
            int take=-1e8;
            if((i+1)<=t) take=price[i]+f(i,price,t-i-1,dp);
            return dp[i][t]=take;
        }
        int notTake=f(i-1,price,t,dp);
        int take=0;
        if((i+1)<=t) take=price[i]+f(i,price,t-i-1,dp);
        return dp[i][t]=max(take, notTake);
    }
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>> dp(n, vector<int> (n+1,-1));
        return f(n-1, price, n, dp);
    }
};

//tabular
class Solution{
  public:
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>> dp(n, vector<int> (n+1,0));
        for(int i=0;i<n;i++) dp[i][0]=0;
        for(int t=1;t<=n;t++) {
            int take=-1e8;
            if((0+1)<=t) take=price[0]+dp[0][t-0-1];
            dp[0][t]=take;
        }
        for(int i=1;i<n;i++){
            for(int t=1;t<=n;t++){
                int notTake=dp[i-1][t];
                int take=0;
                if((i+1)<=t) take=price[i]+dp[i][t-i-1];
                dp[i][t]=max(take, notTake);
            }
        }
        return dp[n-1][n];
    }
};