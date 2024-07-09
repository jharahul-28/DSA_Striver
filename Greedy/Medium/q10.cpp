class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int n=intervals.size();
        sort(intervals.begin(), intervals.end());
        ans.push_back(intervals[0]);
        int end=intervals[0][1],j=0;
        for(int i=1;i<n;i++){
            if(intervals[i][0]<=end){
                ans[j][1]=max(intervals[i][1],ans[j][1]);
                end=max(end,intervals[i][1]);
            }
            else{
                j++;
                end=max(end,intervals[i][1]);
                ans.push_back({intervals[i][0],end});
            }
        }
        return ans;
    }
};