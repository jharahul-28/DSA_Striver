class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<pair<int,int>> adj[n+1];
        for(auto it: edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> parent(n+1), dist(n+1,1e9);
        for(int i=0;i<=n;i++) parent[i]=i;
        dist[1]=0;
        pq.push({0,1});
        while(!pq.empty()){
            auto t=pq.top();
            int node=t.second;
            int dis=t.first;
            pq.pop();
            for(auto it:adj[node]){
                int adjNode=it.first;
                int nodeWeight=it.second;
                if(dis+nodeWeight < dist[adjNode]){
                    dist[adjNode]=dis+nodeWeight;
                    pq.push({dis+nodeWeight,adjNode});
                    parent[adjNode]=node;
                }
            }
        }
        if(dist[n]==1e9) return {-1};
        vector<int> ans;
        int node=n;
        while(parent[node]!=node){
            ans.push_back(node);
            node=parent[node];
        }
        ans.push_back(1);
        ans.push_back(dist[n]);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};