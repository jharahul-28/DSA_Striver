class Solution {
  public:
    string preToInfix(string pre_exp) {
        // Write your code here
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
        return st.top();
    }
};