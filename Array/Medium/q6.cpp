//brute
vector<int> rearrangeArray(vector<int> &nums)
{
    vector<int> vp;
    vector<int> vn;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] <= 0)
            vn.push_back(nums[i]);
        else
            vp.push_back(nums[i]);
    }
    nums.clear();
    int i;
    for (i = 0; i < vp.size() && i < vn.size(); i++)
    {
        nums.push_back(vp[i]);
        nums.push_back(vn[i]);
    }
    //code if -ves != +ves
    if(vp.size>vn.size()){
        while(i<vp.size()){
            nums.push_back(vp[i]);
        }
    }
    else{
        while(i<vn.size()){
            nums.push_back(vn[i]);
        }
    }
    return nums;
}

//better
vector<int> rearrangeArray(vector<int> &nums){
    int odd=1, even=0;
    vector <int> ans(nums.size());
    for(int i=0;i<nums.size();i++){
        if(nums[i]<0){
            ans[odd]=nums[i];
            odd+=2;
        }
        else{
            ans[even]=nums[i];
            even+=2;
        }
    }
    return ans;
}