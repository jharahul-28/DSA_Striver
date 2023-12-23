class Solution {
public:
    bool isP(string p, int s, int e){
        while(s<=e){
            if(p[s++]!=p[e--]) return false;
        }
        return true;
    }
    void partitionHelp(int ind, vector<vector<string>>&ans,vector<string> &path,string s){
        if(ind==s.size()){
            ans.push_back(path);
            return;
        }
        for(int i=ind;i<s.size();i++){
            if(isP(s,ind,i)){
                path.push_back(s.substr(ind,i-ind+1));
                partitionHelp(i+1,ans,path,s);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        partitionHelp(0,ans,path,s);
        return ans;
    }
};