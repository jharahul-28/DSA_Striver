class Solution {
public:
    void f(int i, vector<int>&ds, vector<vector<int>> &ans, int k, int n){
        if(k==0){
            if(n==0)
            ans.push_back(ds);
            return;
        }
        for(int j=i;j<10;j++){
            ds.push_back(j);
            f(j+1,ds,ans,k-1,n-j);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> ds;
        vector<vector<int>> ans;
        f(1,ds,ans,k,n);
        return ans;
    }
};