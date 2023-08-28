//better
set<vector<int>> threeSum(vector<int>& nums) {
    set <vector<int>> st;
    for(int i=0;i<nums.size();i++){
        set <int> hashSet;
        for(int j=i+1;j<nums.size();j++){
            int req=-1*(nums[i]+nums[j]);
            if(hashSet.find(req)!=hashSet.end()){
                vector<int> v={nums[i],nums[j],req};
                sort (v.begin(),v.end());
                st.insert(v);
            }
            hashSet.insert(nums[j]);
        }
    }
    return st;
}

//optimal
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector <vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
        
        int left=i+1, right=nums.size()-1;
        if(i>0 && nums[i]==nums[i-1]) continue;
        while(left<right){
            vector <int> temp;
            if((nums[i]+nums[left]+nums[right])==0){
                temp.push_back(nums[i]);
                temp.push_back(nums[left]);
                temp.push_back(nums[right]);
                ans.push_back(temp);
                left++;
                right--; 
                while(left< right && nums[left]==nums[left-1]) left++;
                while(left< right && nums[right]==nums[right+1]) right--;

            }
            else if((nums[i]+nums[left]+nums[right])>0){
                right--;
            }
            else 
            left++;
        }
    }
    return ans;
    }
};