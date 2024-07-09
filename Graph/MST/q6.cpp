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

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int e=connections.size();
        if(e<(n-1)) return -1;
        DisJointSet ds(n);
        for(int i=0;i<e;i++){
            ds.unionByRank(connections[i][0],connections[i][1]);
        }
        int cmp=0;
        for(int i=0;i<n;i++){
            if (ds.parent[i]==i) cmp++;
        }
        return cmp-1;
    }
};