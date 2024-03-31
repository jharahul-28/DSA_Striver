class Solution {
public:
    int f(int m, int n, string& s, string& t, vector<vector<int>>& dp){
        if(m<0) return n+1;
        if(n<0) return m+1;
        if(dp[m][n]!=-1) return dp[m][n];
        if(s[m]==t[n]) return dp[m][n]=f(m-1,n-1,s,t,dp);
        return dp[m][n]=1+min(f(m,n-1,s,t,dp), min(f(m-1,n,s,t,dp),f(m-1,n-1,s,t,dp)));
    }
    int minDistance(string s, string t) {
        int m=s.length();
        int n=t.length();
        vector<vector<int>> dp(m, vector<int> (n,-1));
        return f(m-1,n-1,s,t,dp);
    }
};