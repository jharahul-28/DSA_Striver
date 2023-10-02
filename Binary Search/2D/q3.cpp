class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=0, col=matrix[0].size()-1;
        while(row<matrix.size() && col>=0){
            int el=matrix[row][col];
            cout<< el<< endl;
            if(el==target) return true;
            else if(el>target) col--;
            else row++;
        }
        return false;
    }
};