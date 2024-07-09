class DisJointSet
{
public:
    vector<int> rank, parent, size;
    DisJointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }
    int findUltParent(int x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = findUltParent(parent[x]);
    }
    void unionByRank(int u, int v)
    {
        int ultP_u = findUltParent(u);
        int ultP_v = findUltParent(v);
        if (ultP_u == ultP_v)
            return;
        else if (rank[ultP_u] < rank[ultP_v])
        {
            parent[ultP_u] = ultP_v;
        }
        else
        {
            parent[ultP_v] = ultP_u;
            rank[ultP_u]++;
        }
    }
};

class Solution
{
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
public:
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int, pair<int, int>>> edge;
        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {
                edge.push_back({it[1], {i, it[0]}});
            }
        }
        DisJointSet ds(V);
        sort(edge.begin(), edge.end());
        int mstwt = 0;
        for (auto it : edge)
        {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            if (ds.findUltParent(u) != ds.findUltParent(v))
            {
                mstwt += wt;
                ds.unionByRank(u, v);
            }
        }
        return mstwt;
    }
};