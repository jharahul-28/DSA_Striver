class Solution {
private:
    int f(vector<vector<int>>& t, int m ,int n, vector<vector<int>> &dp){
        if(m==0 && n==0) return t[m][n];
        if(m<0 || n<0 || n>=t[m].size()) return INT_MAX;
        if(dp[m][n]!=-1) return dp[m][n];
        int t1=f(t,m-1,n,dp);
        int t2=f(t,m-1,n-1,dp);
        return dp[m][n]=min(t1,t2)+t[m][n];
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        vector<vector<int>> dp(m,vector<int> (m,-1));
        int mini=INT_MAX;
        for(int i=0;i<m;i++){
            mini=min(mini,f(triangle, m-1, i, dp));
        }
        return mini;
    }
};