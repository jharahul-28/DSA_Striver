class Solution {
  public:
    int pre(char c){
        if(c=='(') return 0;
        else if(c=='+' || c=='-') return 1;
        else if(c=='*' || c=='/') return 2;
        else return 3;
    }
    string preToPost(string pre_exp) {
        stack <string> st;
        int n=pre_exp.size();
        for(int i=n-1;i>=0;i--){
            auto c=pre_exp[i];
            if((c<='z' && c>='a')||(c<='Z' && c>='A')) {
                st.push(string(1,c));
            }
            else{
                auto op1=st.top();
                st.pop();
                auto op2=st.top();
                st.pop();
                st.push("("+op1+c+op2+")");
            }
        }
        string s=st.top();
        string ans="";
        stack <char> stk;
        for(int i=0;i<s.size();i++){
            char c=s[i];
            if((c<='z' && c>='a')||(c<='Z' && c>='A')) ans.push_back(c);
            else {
                if(c=='(') {
                    stk.push(c);
                    continue;
                }
                else if(c==')'){
                    while(!stk.empty() && stk.top()!='(') {
                        ans.push_back(stk.top());
                        stk.pop();
                    }
                    if(!stk.empty()) stk.pop();
                }
                else{
                    while(!stk.empty() && pre(stk.top())>=pre(c)){
                        ans.push_back(stk.top());
                        stk.pop();
                    }
                    stk.push(c);
                }
            }
        }
        while(!stk.empty()){
            ans.push_back(stk.top());
            stk.pop();
        }
        return ans;
    }
};