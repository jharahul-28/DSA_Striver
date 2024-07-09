int minSubsetSumDifference(vector<int> &nums, int n)
{
  int totSum = 0;
  for (int i = 0; i < n; i++)
    totSum += nums[i];
  vector<vector<bool>> dp(n, vector<bool>(totSum + 1, false));
  for (int i = 0; i < n; i++)
  {
    dp[i][0] = true;
  }
  if (nums[0] <= totSum)
    dp[0][totSum] = true;
  for (int i = 1; i < n; i++)
  {
    for (int target = 1; target <= totSum; target++)
    {
      auto notTake = dp[i - 1][target];
      auto take = false;
      if (nums[i] <= target)
        take = dp[i - 1][target - nums[i]];
      dp[i][target] = notTake || take;
    }
  }
  int ans = 1e9;
  for (int i = 0; i <= totSum; i++)
  {
    if (dp[n - 1][i] == true)
    {
      int diff = abs(i - (totSum - i));
      ans = min(ans, diff);
    }
  }
  return ans;
}
