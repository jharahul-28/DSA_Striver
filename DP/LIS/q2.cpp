vector<int> printingLongestIncreasingSubsequence(vector<int> nums, int n) {
    vector<int> dp(n,1);
    for(int i=0;i<n;i++){
		int maxi=0;
		for(int j=0;j<i;j++){
			if(nums[i]>nums[j]){
				maxi=max(maxi,dp[j]);
			}
		}
		dp[i]+=maxi;
    }
    int maxi=0;
    for(int i=1;i<n;i++){
		if(dp[i]>dp[maxi]) maxi=i;
	}
	int j=dp[maxi];
	vector<int> ans(j);
	j--;
	ans[j]=nums[maxi];
	j--;
	for(int i=maxi-1;i>=0;){
		if(dp[i]==(dp[maxi]-1)){
			ans[j]=nums[i];
			maxi=i;
			j--;
			i--;
		}
		while(dp[i]!=(dp[maxi]-1)){
			i--;
			if(i<0) break;
		}
	}
	return ans;
}
