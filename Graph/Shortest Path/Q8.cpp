class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        for(auto it: times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int> time(n+1, INT_MAX);
        time[k]=0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,k});
        while(!pq.empty()){
            auto t=pq.top();
            pq.pop();
            int nodeTime=t.first;
            int node=t.second;
            for(auto it:adj[node]){
                if(nodeTime + it.second< time[it.first]){
                    time[it.first]=nodeTime + it.second;
                    pq.push({time[it.first], it.first});
                }
            }
        }
        int ans=INT_MIN;
        for(int i=1;i<=n;i++){
            if(time[i]==INT_MAX) return -1;
            if(time[i]>ans) ans=time[i];
        }
        return ans;
    }
};