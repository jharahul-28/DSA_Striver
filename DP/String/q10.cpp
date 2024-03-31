class Solution {
public:
int f(int i,int j, string& p, string& t, vector<vector<int>>& dp){
   if(i<0 && j<0) return true;
   if(i<0 && j>=0) return false;
   if(j<0 && i>=0) {
      for(int a=0;a<=i;a++){
         if(p[a]!='*') return false;
      }
      return true;
   }
   if(dp[i][j]!=-1) return dp[i][j];
   if(p[i]==t[j] || p[i]=='?') return dp[i][j]= f(i-1,j-1,p,t,dp);
   if(p[i]=='*') return dp[i][j]= (f(i-1,j,p,t,dp) || f(i,j-1,p,t,dp));
   return dp[i][j]= false;
}
    bool isMatch(string t, string p) {
        int n=p.length();
        int m=t.length();
        vector<vector<int>> dp(n,vector<int> (m,-1));
        return f(n-1,m-1,p,t,dp);
    }
};