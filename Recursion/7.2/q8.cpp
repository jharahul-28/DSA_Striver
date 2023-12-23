class Solution {
public:
    void f(vector<int>& c, int t, vector<int>&ds,vector<vector<int>> &ans, int i){
        if(t==0){
            ans.push_back(ds);
            return;
        }
        for(int j=i;j<c.size();j++){
            if(c[j]>t) break;
            if(j!=i && c[j]==c[j-1]) continue;
            ds.push_back(c[j]);
            f(c,t-c[j],ds,ans,j+1);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>ds;
        vector<vector<int>> ans;
        sort(candidates.begin(),candidates.end());
        f(candidates, target, ds, ans, 0);
        return ans;
    }
};