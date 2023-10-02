class Solution {
    private:
    int sumOfDivisor(vector<int>& nums, int mid){
        int s=0;
        for(int i=0;i<nums.size();i++){
            s+= nums[i]%mid ? nums[i]/mid +1 : nums[i]/mid; 
        }
        return s;
    }
    public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        int low=1, high=nums[n-1];
        int ans;
        while(low<=high){
            int mid=(low+high)/2;
            int sum=sumOfDivisor(nums,mid);
            if(sum<=threshold) {
                high=mid-1;
                ans=mid;
            }
            else low=mid+1;
        }
        return ans;
    }
};