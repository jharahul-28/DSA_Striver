class Solution{
public:
    void rev(stack<int>& st, int i, int x){
        if(st.size()==i || st.empty()) {
            st.push(x);
            return;
        }
        int top=st.top();
        st.pop();
        rev(st,i,x);
        st.push(top);
    }
    void Reverse(stack<int> &st){
        for(int i=0;i<st.size();i++){
            int top=st.top();
            st.pop();
            rev(st,i,top);
        }
    }
};