class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1) return -1;
        int n=grid.size();
        if(n==1) return 1;
        queue<pair<int,pair<int,int>>> q;
        vector<vector<int>> dist(n, vector<int> (n,1e9));
        dist[0][0]=0;
        q.push({0,{0,0}});
        int dr[]={-1,0,1,0,-1,1,-1,1};
        int dc[]={0,1,0,-1,-1,1,1,-1};
        while(!q.empty()){
            auto t=q.front();
            q.pop();
            int dis=t.first;
            auto coor=t.second;
            int row=coor.first;
            int col=coor.second;
            for(int i=0;i<8;i++){
                int nrow=row+dr[i];
                int ncol=col+dc[i];
                if(nrow>=0 && ncol<n && nrow<n && ncol>=0 && grid[nrow][ncol]==0 && dist[nrow][ncol]==1e9){
                    dist[nrow][ncol]=dis+1;
                    q.push({dist[nrow][ncol],{nrow,ncol}});
                    if(nrow==n-1 && ncol==n-1) return dist[nrow][ncol]+1;
                }
            }
        }
        return -1;
    }
};