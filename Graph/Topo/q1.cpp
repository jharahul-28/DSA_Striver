class Solution
{
    private:
    void dfs(int i, vector<int> adj[], vector<int> &vis, stack<int> &s){
        vis[i]=1;
        for(auto it:adj[i]){
            if(vis[it]==0){
                dfs(it,adj,vis,s);
            }
        }
        s.push(i);
    }
	public:
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> vis(V+1,0);
	    stack <int> s;
	    for(int i=0;i<V;i++){
	        if(vis[i]==0) {
	            dfs(i,adj,vis,s);
	        }
	    }
	    vector<int> ans;
	    while(s.size()>0){
	        ans.push_back(s.top());
	        s.pop();
	    }
	    return ans;
	}
};