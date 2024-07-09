class Solution
{
	public: 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> inDeg(V,0);
	    for(int i=0;i<V;i++){
	        for(auto itr: adj[i]){
	            inDeg[itr]++;
	        }
	    }
	    queue <int> q;
	    for(int i=0;i<V;i++){
	        if(inDeg[i]==0) q.push(i);
	    }
	    vector<int> ans;
	    while(!q.empty()){
	        auto t=q.front();
	        q.pop();
	        ans.push_back(t);
	        for(auto it:adj[t]) {
	            inDeg[it]--;
	            if(inDeg[it]==0) q.push(it);
	        }
	    }
	    return ans;
	}
};