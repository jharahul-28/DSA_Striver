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
        if(nums.size()==1) return nums[0];
        vector<int> dp(nums.size()+1,-1);
        vector<int> temp1, temp2;
        for(int i=0;i<nums.size();i++){
            if(i!=0) temp2.push_back(nums[i]);
            if(i!=(nums.size()-1)) temp1.push_back(nums[i]);
        }
        vector<int> dp2(nums.size()+1,-1);
        return max(f(temp1,0,dp),f(temp2,0,dp2));
    }
};