class Solution {
public:
    bool isValid(string s) {
        int len=s.length();
        stack<char> st;
        for(int i=0;i<len;i++){
            if(s[i]=='('||s[i]=='{'||s[i]=='[')
            st.push(s[i]);
            else if(st.size()==0) return false;
            else if(s[i]==')'){
                if(st.top()=='(')
                st.pop();
                else return false;
            }
            else if(s[i]=='}'){
                if(st.top()=='{')
                st.pop();
                else return false;
            }
            else if(s[i]==']'){
                if(st.top()=='[')
                st.pop();
                else return false;
            }
        }
        return st.empty();
    }
};