class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==1) return strs[0];
        int minLen=INT_MAX, pos=-1;
        for(int i=0;i<strs.size();i++){
            if(strs[i].size()<minLen){
                minLen=strs[i].size();
                pos=i;
            } 
        }
        char ch=strs[0][0];
        for(int i=1;i<strs.size();i++){
            if(strs[i][0]!=ch) return "";
        }
        int f=1;
        int x=0;
        for(int j=0;j<minLen && f;j++){
            char c=strs[pos][j];
            for(int i=0;i<strs.size() && f;i++){
                if(strs[i][j]!=c)
                {
                    f=0;
                    break;
                }
            }
            if(f) x=j;
        }
        return strs[pos].substr(0,x+1);
    }
};