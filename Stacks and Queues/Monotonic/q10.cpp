class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> lv(n), rv(n);
        stack<int> sl, sr;
        for(int i=0;i<n;i++){
            while(!sl.empty() && heights[sl.top()]>=heights[i]){
                sl.pop();
            }
            if(sl.empty()) lv[i]=0;
            else lv[i]=sl.top()+1;
            sl.push(i);
        }
        for(int i=n-1;i>=0;i--){
            while(!sr.empty() && heights[sr.top()]>=heights[i]){
                sr.pop();
            }
            if(sr.empty()) rv[i]=n;
            else rv[i]=sr.top();
            sr.push(i);
        }
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            int x=abs(rv[i]-lv[i])*heights[i];
            ans=max(ans,x);
        }
        return ans;
    }
};