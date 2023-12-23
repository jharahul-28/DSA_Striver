class Solution {
public:
    string c(char i){
        if(i=='2') return "abc";
        else if(i=='3') return "def";
        else if(i=='4') return "ghi";
        else if(i=='5') return "jkl";
        else if(i=='6') return "mno";
        else if(i=='7') return "pqrs";
        else if(i=='8') return "tuv";
        else return "wxyz";
    }
    void f(string &d, int ind, vector<string> & ans, string &s){
        if(ind==d.size()){
            ans.push_back(s);
            return;
        }
        string str=c(d[ind]);
        for(int i=0;i<str.size();i++){
            s.push_back(str[i]);
            f(d,ind+1,ans,s);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
         vector<string> ans;
         string s;
         if(digits.size()==0) return ans;
         f(digits,0,ans,s);
         return ans;
    }
};