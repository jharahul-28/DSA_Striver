class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==1) return true;
        if(nums[0]==0) return false;
        int maxi=nums[0];
        for(int i=1;i<nums.size();i++){
            if(i==nums.size()-1) return true;
            maxi--;
            maxi=max(maxi,nums[i]);
            if(maxi<=0) return false;
        }
        return true;
    }
};