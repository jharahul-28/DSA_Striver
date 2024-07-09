class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        priority_queue<vector<int> , vector<vector<int>>, greater<vector<int>>> pq;
        vector<int> dist(n,1e9);
        dist[src]=0;
        pq.push({0,0,src});
        while(!pq.empty()){
            auto t=pq.top();
            pq.pop();
            int stop=t[0];
            int dis=t[1];
            int node=t[2];
            if(stop==k+1) break;
            for(auto it:adj[node]){
                if(dis+it.second < dist[it.first]){
                    dist[it.first]= dis+it.second;
                    pq.push({stop+1, dist[it.first], it.first});
                }
            }
        }
        if(dist[dst]==1e9) return -1;
        else return dist[dst];
    }
};