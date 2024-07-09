class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> adj[n];
        int modulo=1e9 +7;
        for(auto it: roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<long long> time(n, LLONG_MAX);
        vector<int> ways(n, 0);
        ways[0]=1;
        time[0]=0;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0,0});
        while(!pq.empty()){
            auto t=pq.top();
            pq.pop();
            long long nodeTime = t.first;
            int node=t.second;
            for(auto it:adj[node]){
                int adjNode=it.first;
                int edgeWeight= it.second;
                if(nodeTime + edgeWeight< time[adjNode]){
                    time[adjNode]=nodeTime + edgeWeight;
                    pq.push({time[adjNode], adjNode});
                    ways[adjNode]=ways[node];
                }
                else if(nodeTime + edgeWeight == time[adjNode]) {
                    ways[adjNode]=(ways[adjNode]+ways[node])%modulo;
                }
            }
        }
        return ways[n-1];
    }
};