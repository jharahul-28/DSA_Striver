class Solution{
public:
    bool check(int node, int color, vector<vector<int>>& adj, vector<int>& c){
        for(auto it: adj[node]){
            if(c[it]==color) return false;
        }
        return true;
    }
    bool paint(int i, vector<vector<int>>& adj, int m ,int n, vector<int>& c){
        if(i==n) return true;
        bool b=false;
        for(int a=1;a<=m;a++){
            if(check(i,a,adj,c)){
                c[i]=a;
                b|=paint(i+1,adj,m,n,c);
                if(b) break;
            }
        }
        return b;
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(graph[i][j]){
                    adj[i].push_back(j);
                }
            }
        }
        vector<int> c(n,-1);
        return paint(0,adj,m,n,c);
    }
};