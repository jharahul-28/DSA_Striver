class Solution {
private:
    void recGen(int n, string &ds, vector <string> &ans, int oc, int diff, int cnt, int ind){
        if(oc==n && diff==0){
            ans.push_back(ds);
            return;
        }
        //if the number of open brackets < the number of balanced brackets required then we can add '('
        if(oc<n){
            string ds1=ds;
            ds1.push_back('(');
            recGen(n,ds1,ans,oc+1,diff+1,cnt,ind+1);
        }
        //if the difference of open and close brackets >then to get balanced parenthesis we can add ')'
        if(diff>0){
            string ds1=ds;
            ds1.push_back(')');
            recGen(n,ds1,ans,oc,diff-1,cnt+1,ind+1);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        string ds="(";
        vector <string> ans;
        recGen(n, ds,ans,1,1,0,1);
        return ans;
    }
};