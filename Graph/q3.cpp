class Solution {
public:
    void dfs(vector <int> adjls[], int vis[], int node){
        vis[node]=1;
        for(auto it: adjls[node]){
            if(!vis[it]){
                dfs(adjls, vis, it);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v=(int)isConnected.size();
        vector <int> adjls[v];
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adjls[i].push_back(j);
                    adjls[j].push_back(i);
                }
            }
        } 
        int vis[v];
        for(int i=0;i<v;i++){
            vis[i]=0;
        }
        int cnt=0;
        for(int i=0;i<v;i++){
            if(!vis[i]){
                cnt++;
                dfs(adjls, vis, i);
            }
        }
        return cnt;
    }
};