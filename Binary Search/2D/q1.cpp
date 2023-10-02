int lowerBound(vector<int> &nums){
    int low = 0, high = nums.size() - 1;
    int ans=high+1;
    while (low <= high){
        int mid = (low + high) / 2;
        if(nums[mid]==1) {
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}
int rowWithMax1s(vector<vector<int>> &matrix, int n, int m)
{
    int maxi=-1,maxInd=-1;;
    for(int i=0;i<n;i++){
        int cnt=lowerBound(matrix[i]);
        int len=m-cnt;
        if(len>maxi){
            maxi=len;
            maxInd=i;
        }
    }
    return maxInd;
}