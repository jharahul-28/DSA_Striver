//memo
class Solution{
public:
    int f(int i, int w, int val[], int wt[], vector<vector<int>>& dp){
        if(i==0){
            return val[i]*(w/wt[i]);
        }
        if(dp[i][w]!=-1) return dp[i][w];
        int notTake=f(i-1,w,val,wt,dp);
        int take=-1e8;
        if(w>=wt[i]) take=val[i]+f(i,w-wt[i],val,wt,dp);
        return dp[i][w]=max(take,notTake);
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>> dp(N, vector<int> (W+1,-1));
        int ans= f(N-1, W, val, wt, dp);
        if(ans==-100000000) return 0;
        return ans;
    }
};

//tabular
class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>> dp(N, vector<int> (W+1,0));
        for(int w=0;w<=W;w++){
            dp[0][w]=val[0]*(w/wt[0]);
        }
        for(int i=1;i<N;i++){
            for(int w=0;w<=W;w++){
                int notTake= dp[i-1][w];
                int take=-1e8;
                if(w>=wt[i]) take=val[i]+dp[i][w-wt[i]];
                dp[i][w]=max(take,notTake);
            }
        }
        return dp[N-1][W];
    }
};