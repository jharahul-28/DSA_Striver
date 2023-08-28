// better
vector<int> majorityElement(vector<int> &nums)
{
    int m = floor(nums.size() / 3);
    unordered_map<int, int> mp;
    set<int> st;
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        mp[nums[i]]++;
        if (mp[nums[i]] > m)
        {
            st.insert(nums[i]);
        }
    }
    for (auto it : st)
    {
        ans.push_back(it);
    }
    return ans;
}

//optimal
vector<int> majorityElement(vector<int> &nums){
    int el1=INT_MIN, el2=INT_MIN, cnt1=0, cnt2=0;
    for(int i=0;i<nums.size();i++){
        if(cnt1==0 && el2!=nums[i]){
            el1=nums[i];
            cnt1=1;
        }
        else if(cnt2==0 && el1!=nums[i]){
            el2=nums[i];
            cnt2=1;
        }
        else if(el1==nums[i])
        cnt1++;
        else if()el2==nums[i]
        cnt2++;
        else{
            cnt1--;
            cnt2--;
        }
    }
    cnt1=0;
    cnt2=0;
    for(int i=0;i<nums.size();i++){
        if(el1==nums[i]) cnt1++;
        if(el2==nums[i]) cnt2++;
    }
    vector <int> ans;
    if(cnt1>floor(nums.size()/3))
    ans.push_back(el1);
    if(cnt2>floor(nums.size()/3))
    ans.push_back(el2);
    return ans;
}