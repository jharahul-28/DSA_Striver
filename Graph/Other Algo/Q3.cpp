class Solution
{
    private:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis, stack<int>& st){
        if(vis[node]==1) return;
        vis[node]=1;
        for(auto it: adj[node]) {
            if(!vis[it]) dfs(it,adj,vis,st);
        }
        st.push(node);
    }
    void dfsT(int node, vector<vector<int>>& adjT, vector<int>& vis){
        vis[node]=1;
        for(auto it: adjT[node]) {
            if(!vis[it]) dfsT(it,adjT,vis);
        }
    }
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        vector<int> vis(V,0);
        stack<int> st;
        for(int i=0;i<V;i++){
            if(!vis[i]) dfs(i,adj,vis,st);
        }
        vector<vector<int>> adjT(V);
        for(int i=0;i<V;i++){
            vis[i]=0;
            for(auto it: adj[i]){
                adjT[it].push_back(i);
            }
        }
        int cnt=0;
        while(!st.empty()){
            int node=st.top();
            st.pop();
            if(!vis[node]){
                cnt++;
                dfsT(node,adjT,vis);
            }
        }
        return cnt;
    }
};