class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> leftnge(n), rightnge(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()<height[i]){
                st.pop();
            }
            if(!st.empty()) rightnge[i]=st.top();
            else {
                rightnge[i]=-1;
                st.push(height[i]);
            }
        }
        stack<int> stk;
        for(int i=0;i<n;i++){
            while(!stk.empty() && stk.top()<height[i]){
                stk.pop();
            }
            if(!stk.empty()) {
                leftnge[i]=stk.top();
            }
            else {
                leftnge[i]=-1;
                stk.push(height[i]);
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(rightnge[i]==-1 || leftnge[i] == -1) continue;
            int mini=min(rightnge[i], leftnge[i]);
            ans+=max(0, mini-height[i]);
        }
        return ans;
    }
};