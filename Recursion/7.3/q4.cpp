void f(int i, int j, vector<vector<int>>& m, int n, string& ds, vector<string>& ans){
        if (i==n-1 && j==n-1  && m[i][j]==1) {
            ans.push_back(ds);
            return ;
            
        }
        if (m[i][j]==0) return ;
        m[i][j]=0;
        if (i+1<n){
            ds+='D';
            f(i+1,j,m,n,ds,ans);
            ds.pop_back();
        }
        if(j+1<n){
            ds+='R';
            f(i,j+1,m,n,ds,ans);
            ds.pop_back();
        }
        if(i-1>=0) {
            ds+='U';
            f(i-1,j,m,n,ds,ans);
            ds.pop_back();
        }
        if((j-1)>=0) {
            ds+='L';
            f(i,j-1,m,n,ds,ans);
            ds.pop_back();
        }
        m[i][j]=1;
        return;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        if (m[0][0]==0) return {"-1"};
        string ds="";
        vector<string> ans;
        f(0,0,m,n,ds,ans);
        return ans;
    }