class Solution {
public:
    void f(vector<int>& a, int t, vector<int>& ds, vector<vector<int>>& ans, int i, int s){
        if(s>t) return;
        if(s==t){
            ans.push_back(ds);
            // ds.clear();
            return;
        }
        if(i==a.size()) return;
        s+=a[i];
        ds.push_back(a[i]);
        f(a,t,ds,ans,i,s);
        ds.pop_back();
        s-=a[i];
        f(a,t,ds,ans,i+1,s);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>ds;
        vector<vector<int>> ans;
        f(candidates, target, ds, ans, 0, 0);
        return ans;
    }
};