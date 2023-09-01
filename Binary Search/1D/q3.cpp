int upperBound(vector<int> &nums, int target){
    int low = 0, high = nums.size() - 1;
    int ans=high+1;
    while (low <= high){
        int mid = (low + high) / 2;
        if(nums[mid]>target) {
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}

//stl function
int ub=upper_bound(arr.begin(),arr.end(), target);              //iterator pointing to the index
int ub=upper_bound(arr.begin(),arr.end(), target)-arr.begin();  //index
int ub=upper_bound(arr ,arr + n, target);