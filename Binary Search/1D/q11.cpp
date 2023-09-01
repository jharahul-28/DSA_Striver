int findKRotation(vector<int> &nums){
    int low=0, high=nums.size()-1;
        int mini=INT_MAX;
        int pos=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]<=nums[high]){
                if(nums[mid]<mini){
                    mini=nums[mid];
                    pos=mid;
                }
                high=mid-1;
            }
            else{
                if(nums[low]<mini){
                    mini=nums[low];
                    pos=mid;
                }
                low=mid+1;
            }
        }
        return pos;    
}