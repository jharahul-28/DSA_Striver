class Solution {
private:
    int f(vector<vector<int>>& t, int m ,int n, vector<vector<int>> &dp){
        if(m==0 && n>-1  && n<t[m].size()) return t[m][n];
        if(m<0 || n<0 || n>=t[m].size()) return INT_MAX;
        if(dp[m][n]!=-1e8) return dp[m][n];
        int t1=f(t,m-1,n,dp);
        int t2=f(t,m-1,n-1,dp);
        int t3=f(t,m-1,n+1,dp);
        int min1=min(t1,t2);
        return dp[m][n]=min(min1,t3)+t[m][n];
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m=matrix.size();
        vector<vector<int>> dp(m,vector<int> (m,-1e8));
        int mini=INT_MAX;
        for(int i=0;i<m;i++){
            mini=min(mini,f(matrix, m-1, i, dp));
        }
        return mini;
    }
};