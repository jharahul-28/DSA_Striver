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
    int removeStones(vector<vector<int>>& stones) {
        int maxRow=0;
        int maxCol=0;
        for(auto it: stones){
            maxRow=max(maxRow, it[0]);
            maxCol=max(maxCol, it[1]);
        }
        DisJointSet ds(maxRow+ maxCol+1);
        unordered_map<int,int> stoneNode;
        for(auto it: stones){
            int nodeRow=it[0];
            int nodeCol= it[1]+maxRow+1;
            ds.unionByRank(nodeRow, nodeCol);
            stoneNode[nodeRow]=1;
            stoneNode[nodeCol]=1;
        }
        int cnt=0;
        for(auto it:stoneNode){
            if(ds.findUltParent(it.first)==it.first) cnt++;
        }
        return stones.size()-cnt;
    }
};