class Solution {
public:
    int f(int ind, int buy, int cd, vector<int>& prices, vector<vector<vector<int>>>& dp){
        if(ind == prices.size()) return 0;
        if(dp[ind][buy][cd]!=-1) return dp[ind][buy][cd];
        int profit=0;
        if(buy==1 && cd==0)
        profit=max(-prices[ind]+f(ind+1,0,0,prices,dp),f(ind+1,1,0,prices,dp));
        else if(buy==1 && cd==1) profit=f(ind+1,1,0,prices,dp);
        else profit=max(prices[ind]+f(ind+1,1,1,prices,dp),f(ind+1,0,0,prices,dp));
        return dp[ind][buy][cd]=profit;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>> (2, vector<int> (2,-1)));
        return f(0,1,0,prices,dp);
    }
};