class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v=graph.size();
        vector<vector<int>> adjrev(v);
        vector<int> inDeg(v,0);
        for(int i=0;i<v;i++){
            for(auto it: graph[i]){
                adjrev[it].push_back(i);
                inDeg[i]++;
            }
        }
        queue<int> q;
        for(int i=0;i<v;i++){
            if(inDeg[i]==0) q.push(i);
        }
        vector<int> ans;
        while(!q.empty()){
            auto t=q.front();
            q.pop();
            ans.push_back(t);
            for(auto it:adjrev[t]){
                inDeg[it]--;
                if(inDeg[it]==0) q.push(it);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};