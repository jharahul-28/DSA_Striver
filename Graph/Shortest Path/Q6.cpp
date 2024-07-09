class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size(), m=heights[0].size();
        vector<vector<int>> effort(n, vector<int> (m, 1e9));
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        effort[0][0]=0;
        int dr[]={0,-1,0,1};
        int dc[]={-1,0,1,0};
        while(!pq.empty()){
            auto t=pq.top();
            pq.pop();
            int height=t.first;
            auto coor=t.second;
            int x=coor.first;
            int y=coor.second;
            for(int i=0;i<4;i++){
                int nr=x+dr[i];
                int nc=y+dc[i];
                if(nr>=0 && nc>=0 && nr<n && nc<m){
                    int maxi=max(height,abs(heights[x][y]-heights[nr][nc]));
                    if(maxi<effort[nr][nc]){
                        effort[nr][nc]=maxi;
                        pq.push({effort[nr][nc], {nr,nc}});
                    }
                }
            }
        }
        return effort[n-1][m-1];
    }
};