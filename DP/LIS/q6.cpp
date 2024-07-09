class Solution {
  public:
    int LongestBitonicSequence(int n, vector<int> &nums) {
        // code here
        int m1=1, m2=1;
        vector<int> dp1(n,1), dp2(n,1);
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(nums[prev]<nums[i] && 1+dp1[prev] > dp1[i]){
                    dp1[i]=1+dp1[prev];
                } 
            }
            m1=max(m1,dp1[i]);
        }
        for(int i=n-1;i>=0;i--){
            for(int prev=n-1;prev>i;prev--){
                if(nums[prev]<nums[i] && 1+dp2[prev] > dp2[i]){
                    dp2[i]=1+dp2[prev];
                } 
            }
            m2=max(m2,dp2[i]);
        }
        int ans=0;
        for(int i=1;i<n-1;i++) {
            if(dp1[i]==1 || dp2[i]==1) continue;
            ans=max(ans, dp1[i]+dp2[i]-1);
        }
        return ans;
    }
};