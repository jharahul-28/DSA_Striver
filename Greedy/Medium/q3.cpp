class Solution {
public:
    int jump(vector<int>& nums) {
        int l=0, r=0, jumps=0;
        int n=nums.size();
        while(r<n-1){
            jumps++;
            int maxInd=l;
            for(int i=l;i<=r;i++){
                maxInd=max(maxInd, nums[i]+i);
            }
            if(maxInd>=n) return jumps;
            l=r+1;
            r=maxInd;
        }
        return jumps;
    }
};