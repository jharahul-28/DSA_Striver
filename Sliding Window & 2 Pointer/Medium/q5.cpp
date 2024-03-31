class Solution {
public:
    int f(vector<int>& nums, int n, int goal){
        if(goal<0) return 0;
        int l=0,r=0,c=0,s=0;
        while(r<n){
            s+=nums[r];
            while(s>goal){
                s-=nums[l];
                l++;
            }
            if(s<=goal) c+=(r-l+1);
            r++;
        }
        return c;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return f(nums,nums.size(),goal)-f(nums,nums.size(),goal-1);
    }
};