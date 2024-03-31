#include <bits/stdc++.h> 
int longestPalindromeSubsequence(string s)
{
    int m=s.length();
    string t="";
    for(int i=m-1;i>=0;i--) t.push_back(s[i]);
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