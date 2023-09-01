//recursive
class Solution {
    private:
    int bs(vector<int>& nums, int target, int low, int high){
        if(low>high){
            return -1;
        }
        else{
            int mid=(low+high)/2;
            if (nums[mid]==target) return mid;
            else if(nums[mid]<target) return bs(nums, target, mid+1, high);
            else return bs(nums, target, low, mid-1);
        }
    }
public:
    int search(vector<int>& nums, int target) {
        int low=0, high=nums.size()-1;
        return bs(nums, target, 0, high);
    }
};

//iterative
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0, high=nums.size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(target> nums[mid]) low=mid+1;
            else if(target< nums[mid]) high=mid-1;
            else return mid;
        }
        return -1;
    }
};