class Solution {
private:
    int maxIndex(vector <int>& nums){
        int n=nums.size();
        int maxi=0;
        for(int i=1;i<n;i++){
            if(nums[i] > nums[maxi])
            maxi=i;
        }
        return maxi;
    }
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int high=mat.size()-1;
        int low=0;
        vector<int> ans;
        while(low<=high){
            int mid=(low+high)/2;
            int maxInd= maxIndex(mat[mid]);
            int top= mid>0? mat[mid-1][maxInd]: -1;
            int bot= mid< (mat.size()-1) ? mat[mid+1][maxInd]: -1;
            if(mat[mid][maxInd]>top && mat[mid][maxInd]>bot){
                ans.push_back(mid);
                ans.push_back(maxInd);
                break;
            }
            else if(bot>top) {
                low=mid+1;
            }
            else{
                high=mid-1;
            } 
        }
        return ans;
    }
};