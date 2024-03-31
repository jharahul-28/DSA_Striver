string findLCS(int m, int n,string &s, string &t){
	vector<vector<int>> dp(m+1, vector<int> (n+1,-1));
	for(int i=0;i<=m;i++) dp[i][0]=0;	
	for(int j=0;j<=n;j++) dp[0][j]=0;
	for(int i=0;i<=m;i++){
		for(int j=0;j<=n;j++){
			if(dp[i][j]!=-1) continue;
			if(s[i-1]==t[j-1]) dp[i][j]=1+dp[i-1][j-1];
			else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);			
		}
	}
	int l=0, i=m, j=n;
	string ans="";
	while(l<dp[m][n]){
		if(s[i-1]==t[j-1]){
			ans.push_back(s[i-1]);
			i--;
			j--;
			l++;
		}
		else {
			if(dp[i][j-1]>dp[i-1][j]) j--;
			else i--;
		}
	}
	for(int i=0;i<l/2;i++){
		char temp=ans[i];
		ans[i]=ans[l-i-1];
		ans[l-i-1]=temp;
	}
	return ans;
}