class Solution {
public:
    bool check(string& s, vector<string>& wordDict, int i, int j, int k, vector<vector<vector<int>>>& memo) {
        if (i == s.size()) {
            return k == wordDict[j].size();
        }
        if (j >= wordDict.size()) return false;
        if (memo[i][j][k] != -1) return memo[i][j][k];
        bool result = false;
        if (k == wordDict[j].size()) {
            for (int a = 0; a < wordDict.size(); a++) {
                if (wordDict[a][0] == s[i]) {
                    result |= check(s, wordDict, i + 1, a, 1, memo);
                }
            }
        } else if (wordDict[j][k] == s[i]) {
            result = check(s, wordDict, i + 1, j, k + 1, memo);
        }
        memo[i][j][k] = result;
        return result;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        int m = wordDict.size();
        vector<vector<vector<int>>> memo(n + 1, vector<vector<int>>(m, vector<int>(n + 1, -1)));
        for (int i = 0; i < m; i++) {
            if (wordDict[i][0] == s[0] && check(s, wordDict, 1, i, 1, memo)) {
                return true;
            }
        }
        return false;
    }
};
