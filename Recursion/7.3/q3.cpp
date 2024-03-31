class Solution {
public:
    bool safe(int ind, int i, int n, vector<string>& board){
        for(int j=0;j<ind;j++){
            if (board[j][i]=='Q') return false;
        }
        int dind=ind, di=i;
        while(dind>-1 && di>-1){
            if(board[dind][di]=='Q') return false;
            dind--;
            di--;
        }
        dind=ind, di=i;
        while(dind>-1 && di<n){
            if(board[dind][di]=='Q') return false;
            dind--;
            di++;
        }
        return true;
    }
    void f(int ind, int n, vector<string>& board, vector<vector<string>>& ans){
        if(ind==n){
            ans.push_back(board);
            return ;
        }
        for(int i=0;i<n;i++){
            if(safe(ind,i,n,board)){
                board[ind][i]='Q';
                f(ind+1,n,board,ans);
                board[ind][i]='.';
            }
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        string s(n,'.');
        vector<string> board;
        for(int i=0;i<n;i++) 
            board.push_back(s);
        vector<vector<string>> ans;
        f(0,n,board,ans);
        return ans;
    }
};