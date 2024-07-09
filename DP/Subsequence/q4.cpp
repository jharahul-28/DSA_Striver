int findWaysUtil(int ind, int n, int target, int arr[], vector<vector<int>> &dp)
{
  if (ind >= n)
    return target == 0;
  if (dp[ind][target] != -1)
    return dp[ind][target];

  int notTaken = findWaysUtil(ind + 1, n, target, arr, dp);
  int taken = 0;
  if (target >= arr[ind])
  {
    taken = findWaysUtil(ind + 1, n, target - arr[ind], arr, dp);
  }

  return dp[ind][target] = (notTaken + taken) % (1000000007);
}

int perfectSum(int arr[], int n, int sum)
{
  vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
  return findWaysUtil(0, n, sum, arr, dp);
}