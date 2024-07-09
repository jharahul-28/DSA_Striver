class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int lastInd=0, maxi=1, prevInd=0, n=nums.size();
        vector<int> dp(n,1), ans, backTrack(n);
        sort(nums.begin(), nums.end());
        for(int i=0;i<n;i++){
            backTrack[i]=i;
            for(int prev=0;prev<i;prev++){
                if(nums[i]%nums[prev]==0 && 1+dp[prev] > dp[i]){
                    dp[i]=1+dp[prev];
                    backTrack[i]=prev;
                } 
            }
            if(dp[i] > maxi){
                maxi= dp[i];
                prevInd=i;
            }
        }
        ans.push_back(nums[prevInd]);
        while(backTrack[prevInd]!=prevInd){
            prevInd= backTrack[prevInd];
            ans.push_back(nums[prevInd]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};