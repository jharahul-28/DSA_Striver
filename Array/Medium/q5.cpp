int StockMaxProfit(vector <int> v){
    int mini=v[0];
    int profit=0;
    for(int i=1;i<v.size();i++){
        mini=min(mini, v[i-1]);
        int currentProfit=v[i]-mini;
        profit= max(profit, currentProfit);
    }
    return profit;
}