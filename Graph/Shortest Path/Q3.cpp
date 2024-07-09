//priority queue
class Solution
{
	public:
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dist(V,1e9);
        dist[S]=0;
        pq.push({0,S});
        while(!pq.empty()){
            auto t=pq.top();
            int node=t.second;
            int dis=t.first;
            pq.pop();
            for(auto it:adj[node]){
                int adjNode=it[0];
                int nodeWeight=it[1];
                if(dis+nodeWeight < dist[adjNode]){
                    dist[adjNode]=dis+nodeWeight;
                    pq.push({dist[adjNode],adjNode});
                }
            }
        }
        return dist;
    }
};

//set
class Solution
{
	public:
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        set<pair<int,int>> st;
        vector<int> dist(V,1e9);
        dist[S]=0;
        st.insert({0,S});
        while(!st.empty()){
            auto t= *(st.begin());
            int node=t.second;
            int dis=t.first;
            st.erase(t);
            for(auto it:adj[node]){
                int adjNode=it[0];
                int nodeWeight=it[1];
                if(dis+nodeWeight < dist[adjNode]){
                    dist[adjNode]=dis+nodeWeight;
                    if(dist[adjNode]!=1e9) st.erase({dist[adjNode],adjNode});
                    st.insert({dist[adjNode],adjNode});
                }
            }
        }
        return dist;
    }
};