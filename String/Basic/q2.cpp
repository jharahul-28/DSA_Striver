class Solution {
public:
    string reverseWords(string s) {
        string ans;
        int i=0;
        string p="";
        while(i<s.size()){
            while(s[i]==' ' && i<s.size()){
            i++;
            }
            p="";
            while(s[i]!=' ' && i<s.size()){
                p.push_back(s[i]);
                i++;
            }
            p.push_back(' ');
            ans.insert(0,p);
        }
        if(ans[0]==' '){
            ans.erase(0,1);
        }
        ans.pop_back();
        return ans;
    }
};