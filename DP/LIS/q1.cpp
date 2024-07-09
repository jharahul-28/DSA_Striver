//memo
class Solution {
public:
    int f(int index, int prev_ind, vector<int>&nums, int n,vector<vector<int>>&dp ){
        if(index==n)return 0;
        if(dp[index][prev_ind+1] != -1)return dp[index][prev_ind+1];    
        int len = 0 + f(index+1, prev_ind, nums, n,dp);

        if(prev_ind == -1 || nums[index] > nums[prev_ind]){
            len = max(len, 1 + f(index+1, index, nums, n,dp));
        } 
        return dp[index][prev_ind+1] = len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return f(0,-1,nums,n,dp);
    }
};

//tabular
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size(), maxi=1;
        vector<int> dp(n,1);
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(nums[prev]<nums[i]){
                    dp[i]= max(dp[i], 1+dp[prev]);
                    maxi=max(maxi,dp[i]);
                } 
            }
        }
        return maxi;
    }
};

//Algo
class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& nums) {
        // Code here
        int lastInd=0, maxi=1;
        vector<int> dp(n,1);
        for(int i=0;i<n;i++){
            backTrack[i]=i;
            for(int prev=0;prev<i;prev++){
                if(nums[prev]<nums[i] && 1+dp[prev] > dp[i]){
                    dp[i]=1+dp[prev];
                } 
            }
            if(dp[i] > maxi){
                maxi= dp[i];
            }
        }
        return maxi;
    }
};