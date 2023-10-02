class Solution {
private:
    int cnt(vector<int>& nums, int mid){
        int c=1;
        int sum=nums[0];
        for(int i=1;i<nums.size();i++){
            sum+=nums[i];
            if(sum>mid){
                c++;
                sum=nums[i];
            }
        }
        return c;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int low=nums[0];
        int high=nums[0];
        for(int i=1;i<nums.size();i++){
            low=max(low,nums[i]);
            high+=nums[i];
        }
        while(low<=high){
            int mid=(low+high)/2;
            int c=cnt(nums,mid);
            if(c<=k) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};