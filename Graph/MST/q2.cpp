class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        int sum=0;
        pq.push({0,0}); 
        vector<int> vis(V,0);
        while(!pq.empty()){
            auto t=pq.top();
            int weight=t.first;
            int node=t.second;
            pq.pop();
            if(vis[node]==1) continue;
            sum+=weight;
            vis[node]=1;
            for(auto it: adj[node]){
                int adjNode=it[0];
                int edW=it[1];
                if(!vis[adjNode]){
                    pq.push({edW,adjNode});
                }
            }
        }
        return sum;
    }
};