class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack <int> st;
        int n=asteroids.size();
        for(int i=0;i<n;i++){
            if(asteroids[i]>0) st.push(asteroids[i]);
            else {
                while(!st.empty() && st.top()>0 && st.top()<(-1*asteroids[i])){
                    st.pop();
                }
                if(!st.empty() && st.top()>(-1*asteroids[i])) continue;
                if(st.empty()) st.push(asteroids[i]);
                else if(st.top()<0 && asteroids[i]<0) st.push(asteroids[i]);
                else if(st.top()==(-1*asteroids[i])) {
                    st.pop();
                    continue;
                }
            }
        }
        int len=st.size();
        vector<int> ans(len);
        for(int i=len-1;i>=0;i--) {
            ans[i]=st.top();
            st.pop();
        }
        return ans;
    }
};