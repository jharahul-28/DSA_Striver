class Solution{
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
    string findOrder(string dict[], int N, int K) {
        vector<int> adj[K];
        for(int i=0;i<N-1;i++){
            int mini=min(dict[i].length(), dict[i+1].length());
            for(int j=0;j<mini;j++){
                if(dict[i][j]!=dict[i+1][j]){
                    adj[dict[i][j]-'a'].push_back(dict[i+1][j]-'a');
                    break;
                }
            }
        }
        vector<int> topo = topoSort(K,adj);
        string ans;
        for(int i=0;i<topo.size();i++)
        ans.push_back(topo[i]+'a');
        return ans;
    }
};
