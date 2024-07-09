//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
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
	    if(ans.size()==V) return false;
	    else return true;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends