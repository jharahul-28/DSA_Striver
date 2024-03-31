class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=prices[0];
        int profit=0;
        for(int i=1;i<prices.size();i++){
            mini=min(mini, prices[i-1]);
            int currentProfit=prices[i]-mini;
            profit= max(profit, currentProfit);
        }
        return profit;
    }
};