class Solution {
private:
    int f(vector<vector<int>>& grid, int m, int n, vector<vector<int>> &dp){
        if(m==0 && n==0) return grid[m][n];
        if(m<0 || n<0) return INT_MAX;
        if(dp[m][n]!=-1) return dp[m][n];
        int l=0, u=0;
        l=f(grid,m,n-1,dp);
        u=f(grid,m-1,n,dp);
        return dp[m][n]=(min(l,u)+grid[m][n]);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int> (n,-1));
        dp[0][0]=grid[0][0];
        return f(grid,m-1,n-1,dp);
    }
};