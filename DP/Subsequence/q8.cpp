//recursion
class Solution {
public:
    int f(int i, vector<int>& nums, int target){
        if(i==0){
            if(target-nums[0]==0 && target+nums[0]==0) return 2;
            if(target-nums[0]==0 || target+nums[0]==0) return 1;
            else return 0; 
        }
        int add=f(i-1,nums,target+nums[i]);
        int sub=f(i-1,nums,target-nums[i]);
        return add+sub;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        return f(n-1,nums,target);
    }
};