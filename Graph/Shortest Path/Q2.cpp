class Solution {
  private:
     void topo(int node, vector<pair<int,int>> adj[], int vis[], stack<int>& st){
         vis[node]=1;
         for(auto it: adj[node]){
             if(!vis[it.first]) topo(it.first,adj,vis,st);
         }
         st.push(node);
     }
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<pair<int,int>> adj[N];
        for(int i=0;i<M;i++){
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        }
        int vis[N]={0};
        stack<int> st;
        for(int i=0;i<N;i++){
            if(!vis[i]) topo(i,adj,vis,st);
        }
        vector<int> dist(N,1e9);
        dist[0]=0;
        while(!st.empty()){
            int node=st.top();
            st.pop();
            for(auto it: adj[node]){
                int v=it.first;
                int wt=it.second;
                if(dist[node]+wt < dist[v]){
                    dist[v]=wt+dist[node];
                }
            }
        }
        for(int i=0;i<N;i++){
            if(dist[i]==1e9) dist[i]=-1;
        }
        return dist;
    }
};