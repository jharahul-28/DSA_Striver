class Solution {
public:
    bool valid(int row, int col, char num, vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            if(board[row][i]==num) return false;
        }
        for(int i=0;i<9;i++){
            if(board[i][col]==num) return false;
        }
        int numr=row/3;
        int numc=col/3;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[numr*3+i][numc*3+j]==num) return false;
            }
        }
        return true;
    
    }
    bool solver(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(board[i][j]=='.'){
                for(char k='1';k<='9';k++){
                    if(valid(i,j,k,board)){
                        board[i][j]=k;
                        
                        if(solver(board)) return true; 
                        board[i][j]='.';
                    }
                }
                return false;
            }
        }
        }
       return true;
    }
    void solveSudoku(vector<vector<char>>& board){
        solver(board);
    }
};