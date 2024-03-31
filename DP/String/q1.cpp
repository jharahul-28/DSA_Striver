//memoization
#include <bits/stdc++.h>
int f(string& s, string& t, int m, int n, vector<vector<int>>& dp){
	if(m<0 || n<0) return 0;
	if(dp[m][n]!=-1) return dp[m][n]; 
	if(s[m]==t[n]) return dp[m][n]=1+f(s,t,m-1,n-1,dp);
	return dp[m][n]=max(f(s,t,m-1,n,dp),f(s,t,m,n-1,dp));
}
int lcs(string s, string t)
{
	int m=s.length();
	int n=t.length();
	vector<vector<int>> dp(m, vector<int> (n,-1));
	return f(s,t,m-1,n-1,dp);
}

//tabulation
#include <bits/stdc++.h>
int lcs(string s, string t)
{
	int m=s.length();
	int n=t.length();
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
	return dp[m][n];
}