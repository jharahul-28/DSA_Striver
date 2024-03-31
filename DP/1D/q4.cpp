class Solution {
public:
    int f(vector<int>& nums, int i, vector<int> &dp){
        if(i>=nums.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int l=f(nums,i+2,dp)+nums[i];
        int r=f(nums,i+1,dp);
        return dp[i]=max(l,r);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1,-1);
        return f(nums,0,dp);
    }
};