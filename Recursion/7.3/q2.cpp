class Solution {
public:
    bool f(int r, int c, int t, vector<vector<char>>& board, string& word,vector<vector<int>> &vis){
        if(t==word.length()) return true;
        if(r<0 || r>=board.size() || c<0 || c>=board[0].size() || vis[r][c] || board[r][c]!=word[t])
        return false;
        bool b1=false,b2=0,b3=0,b4=0;
        vis[r][c]=1;
        b1=f(r+1,c,t+1,board,word,vis);
        b2=f(r-1,c,t+1,board,word,vis);
        b3=f(r,c+1,t+1,board,word,vis);
        b4=f(r,c-1,t+1,board,word,vis);
        vis[r][c]=0;
        return (b1 || b2 || b3 || b4);
    }
    bool exist(vector<vector<char>>& board, string word) {
        int r=board.size();
        int c=board[0].size();
        int l=word.size();
        string temp="";
        vector<vector<int>> vis(r,vector<int>(c,0));
        bool f1=false;
        for(int i=0;i<r;++i){
            for(int j=0;j<c;++j){
                if(board[i][j]==word[0]){
                    f1|= f(i,j,0,board,word,vis);
                }
            }
        }
        return f1;
        
    }
};