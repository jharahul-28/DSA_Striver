class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        vector<vector<int>> adj(N);
        for(int i=0;i<M;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> ans(N,-1);
        ans[src]=0;
        queue<pair<int,int>> q;
        q.push({src,0});
        while(!q.empty()){
            auto t=q.front();
            q.pop();
            auto first=t.first;
            auto second=t.second;
            if (ans[first]==-1) ans[first]=second;
            else second=ans[first];
            for(auto it:adj[first]){
                if(ans[it]==-1){
                    q.push({it,second+1});
                }
            }
        }
        return ans;
    }
};
