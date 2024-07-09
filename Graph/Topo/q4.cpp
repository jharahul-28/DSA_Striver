class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(V);
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
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
	    if(ans.size()==V) return true;
	    else return false;
    }
};