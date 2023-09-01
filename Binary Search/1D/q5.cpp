//ceil: smallest number in array >= target
int ceil(vector<int> &nums, int target){
    int low = 0, high = nums.size() - 1;
    int ans= nums[high+1];
    while (low <= high){
        int mid = (low + high) / 2;
        if(nums[mid]>=target) {
            ans= nums[mid];
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}

//floor: largest number in array <= target
int floor(vector<int> &nums, int target){
    int low = 0, high = nums.size() - 1;
    int ans= nums[high+1];
    while (low <= high){
        int mid = (low + high) / 2;
        if(nums[mid]<=target) {
            ans= nums[mid];
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return ans;
}