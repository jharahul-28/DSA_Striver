class Solution {
  public:
    string postToInfix(string exp) {
        // Write your code here
        stack <string> st;
        int n=exp.size();
        for(int i=0;i<n;i++){
            auto c=exp[i];
            if((c<='z' && c>='a')||(c<='Z' && c>='A')) {
                st.push(string(1,c));
            }
            else{
                auto op1=st.top();
                st.pop();
                auto op2=st.top();
                st.pop();
                st.push("("+op2+c+op1+")");
            }
        }
        return st.top();
    }
};