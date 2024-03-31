class Solution {
public:
    bool partition(int ind, int target, vector<int>& nums, vector<vector<int>>& dp){
        if(target==0) 
            return true;
        if(ind==0) 
            return nums[0]==target;
        if(dp[ind][target]!=-1) 
            return dp[ind][target];
        bool notTake=partition(ind-1,target, nums, dp);
        bool take=false;
        if(nums[ind]<=target){
            take=partition(ind-1,target-nums[ind],nums,dp);
        }
        return dp[ind][target]= notTake || take ;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++) sum+=nums[i];
	    if(sum%2==1) return false;
        int k=sum/2;
        vector<vector<int>> dp(n, vector<int> (k+1, -1));
        return partition(n-1, k, nums, dp);
    }
};