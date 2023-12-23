class Solution {
public:
    void f(vector<int>& n, vector<int>& ds, vector<vector<int>>& a, int i){
        a.push_back(ds);
        for(int j=i;j<n.size();j++){
            if(j!=i && n[j]==n[j-1]) continue;
            ds.push_back(n[j]);
            f(n,ds,a,j+1);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
         vector<vector<int>> ans;
         vector<int> ds;
         sort(nums.begin(),nums.end());
         f(nums,ds,ans,0);
         return ans;
    }
};