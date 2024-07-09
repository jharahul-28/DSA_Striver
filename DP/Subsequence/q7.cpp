// memoization
class Solution
{
public:
  int ways(int n, vector<int> &coins, int amount, vector<vector<int>> &dp)
  {
    if (amount < 0)
      return 1e8;
    if (amount == 0)
      return 0;
    if (dp[n][amount] != -1)
      return dp[n][amount];
    if (n == 0)
    {
      if (amount % coins[0] == 0)
        return amount / coins[0];
      return 1e8;
    }
    int notTake = ways(n - 1, coins, amount, dp);
    int take = 1e8;
    if (coins[n] <= amount)
      take = 1 + ways(n, coins, amount - coins[n], dp);
    return dp[n][amount] = min(take, notTake);
  }
  int coinChange(vector<int> &coins, int amount)
  {
    if (amount == 0)
      return 0;
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    int ans = ways(n - 1, coins, amount, dp);
    if (ans == 1e8)
      return -1;
    else
      return ans;
  }
};

// tabulation
class Solution
{
public:
  int coinChange(vector<int> &coins, int amount)
  {
    if (amount == 0)
      return 0;
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, 1e8));
    for (int i = 0; i < n; i++)
      dp[i][0] = 0;
    for (int i = 1; i <= amount; i++)
    {
      if (i % coins[0] == 0)
        dp[0][i] = i / coins[0];
    }
    for (int i = 1; i < n; i++)
    {
      for (int a = 1; a <= amount; a++)
      {
        int notTake = dp[i - 1][a];
        int take = 1e8;
        if (coins[i] <= a)
          take = 1 + dp[i][a - coins[i]];
        dp[i][a] = min(take, notTake);
      }
    }
    int ans = dp[n - 1][amount];
    if (ans == 1e8)
      return -1;
    else
      return ans;
  }
};