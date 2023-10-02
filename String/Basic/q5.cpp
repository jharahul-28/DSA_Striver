class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map <char,char> mpp;
        int l1=s.size();
        int l2=t.size();
        if(l1!=l2) return false;
        for(int i=0;i<l1;i++){
            if(mpp.find(t[i])==mpp.end()){
                mpp[t[i]]=s[i];
            }
            else{
                if(mpp[t[i]]!=s[i]){
                    return false;
                }
            }
        }
        mpp.clear();
        for(int i=0;i<l1;i++){
            if(mpp.find(s[i])==mpp.end()){
                mpp[s[i]]=t[i];
            }
            else{
                if(mpp[s[i]]!=t[i]){
                    return false;
                }
            }
        }
        return true;
    }
};