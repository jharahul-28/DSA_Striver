class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    int pre(char c){
        if(c=='(') return 0;
        else if(c=='+' || c=='-') return 1;
        else if(c=='*' || c=='/') return 2;
        else return 3;
    }
    
    string infixToPostfix(string s) {
        // Your code here
        string ans="";
        stack <char> st;
        for(int i=0;i<s.size();i++){
            char c=s[i];
            if((c<='z' && c>='a')||(c<='Z' && c>='A')) ans.push_back(c);
            else {
                if(c=='(') {
                    st.push(c);
                    continue;
                }
                else if(c==')'){
                    while(!st.empty() && st.top()!='(') {
                        ans.push_back(st.top());
                        st.pop();
                    }
                    if(!st.empty()) st.pop();
                }
                else{
                    while(!st.empty() && pre(st.top())>=pre(c)){
                        ans.push_back(st.top());
                        st.pop();
                    }
                    st.push(c);
                }
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};