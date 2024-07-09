//works for recursion, need to memoize

class Solution {
  public:
    int rec(int i,int n, string s, string str, set<string> &st){
        if(i==n){
            if(st.find(str)==st.end()){
                st.insert(str);
                return 1;
            }
            else return 0;
        }
        str.push_back(s[i]);
        int l=rec(i+1,n,s,str,st);
        str.pop_back();
        int r=rec(i+1,n,s,str,st);
        return l+r;
    }
    int helper(string s){
        int n=s.size();
        string str;
        set<string> st;
        return rec(0,n,s,str,st);
    }
    string betterString(string str1, string str2) {
        // code here
        if (helper(str1)>=helper(str2)) return str1;
        else  return str2;
    }
};