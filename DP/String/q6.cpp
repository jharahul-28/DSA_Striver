class Solution
{
public:
    int minDistance(string s, string t)
    {
        int m = s.length();
        int n = t.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        for (int i = 0; i <= m; i++)
            dp[i][0] = 0;
        for (int j = 0; j <= n; j++)
            dp[0][j] = 0;
        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                if (dp[i][j] != -1)
                    continue;
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        int k = m - dp[m][n];
        int l = n - dp[m][n];
        return k + l;
    }
};