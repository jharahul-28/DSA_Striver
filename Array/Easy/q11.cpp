int maxConsecutive1(vector <int>& nums){
    int max1=0, cnt=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]==1){
            cnt++;
            max(max1, nums);
        }
        else {
            cnt=0;
        }
    }
    return cnt;
}