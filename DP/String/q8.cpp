class Solution {
public:
    int f(int m, int n, string& s, string& t, vector<vector<int>>& dp){
        if(n<0) return 1;
        if(m<0) return 0;
        if(dp[m][n]!=-1) return dp[m][n];
        if(s[m]==t[n]) return dp[m][n]=f(m-1,n-1,s,t,dp)+f(m-1,n,s,t,dp);
        else return dp[m][n]=f(m-1,n,s,t,dp);
    }
    int numDistinct(string s, string t) {
        int m=s.length();
        int n=t.length();
        vector<vector<int>> dp(m, vector<int> (n,-1));
        return f(m-1,n-1,s,t,dp);
    }
};