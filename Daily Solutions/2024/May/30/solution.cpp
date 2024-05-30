#### C++

class Solution {
  public:
    int countWays(string s1, string s2) {
        // code here
        const int MOD = 1e9 + 7;
        int n = s1.length();
        int m = s2.length();
    
        // Create a 2D DP array with dimensions (n+1) x (m+1)
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));
    
        // Initialization: If s2 is empty, there's exactly one subsequence that matches (the empty subsequence)
        for (int i = 0; i <= n; ++i) {
            dp[i][0] = 1;
        }
    
        // Fill the DP array based on the transition rules
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                // If the characters match, we can either include the character from s1 or exclude it
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
                } else {
                    // If the characters don't match, we can only exclude the character from s1
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
    
        // The result is the number of subsequences of s1 that form s2, stored in dp[n][m]
        return dp[n][m];
    }
};
