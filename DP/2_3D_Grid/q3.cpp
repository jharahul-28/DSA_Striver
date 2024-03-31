// Memoization
class Solution {
private:
    int f(vector<vector<int>>& obstacleGrid, int m, int n, vector<vector<int>>& dp){
        if(m==0 && n==0) return 1;
        if(m<0 || n<0) return 0;
        if(dp[m][n]!=-1) return dp[m][n];
        int l=0,u=0;
        if((n-1)>-1 && obstacleGrid[m][n-1]!=1)
        l=f(obstacleGrid,m,n-1,dp);
        if((m-1)>-1 && obstacleGrid[m-1][n]!=1)
        u=f(obstacleGrid,m-1,n,dp);
        return dp[m][n]=(l+u);
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        if(obstacleGrid[m-1][n-1]==1) return 0;
        vector<vector<int>> dp(m,vector<int> (n,-1));
        return f(obstacleGrid,m-1,n-1,dp);
    }
};

// Tabular
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        if(obstacleGrid[m-1][n-1]==1) return 0;
        vector<vector<int>> dp(m,vector<int> (n,-1));
        dp[0][0]=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(dp[i][j]==-1){
                    int l=0,u=0;
                    if((j-1)>-1 && obstacleGrid[i][j-1]!=1)
                    l=dp[i][j-1];
                    if((i-1)>-1 && obstacleGrid[i-1][j]!=1)
                    u=dp[i-1][j];
                    dp[i][j]= l+u;
                }
            }
        }
        return dp[m-1][n-1];
    }
};