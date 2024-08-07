class Solution{
public:
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        vector<vector<int>> dp(N, vector<int> (N,0));
        for(int i=0;i<N;i++){
            dp[i][i]=0;
        }
        for(int i=N-1;i>=1;i--){
            for(int j=i+1;j<N;j++){
                int mini=INT_MAX;
                for(int k=i;k<j;k++){
                    mini=min(mini, arr[i-1]*arr[k]*arr[j]+dp[i][k]+dp[k+1][j]);
                }
                dp[i][j]=mini;
            }
        }
        return dp[1][N-1];
    }
};