#### C++

class Solution {
  public:
    int findWinner(int n, int x, int y) {
        // code here
        // DP array to store results for subproblems
        vector<bool> dp(n + 1, false);
        
        // Base case: If there are 0 coins, Geek cannot make a move and hence cannot win
        dp[0] = false;
        
        // Fill the dp array for all values from 1 to n
        for (int i = 1; i <= n; ++i) {
            // Check if there's a move that forces the opponent into a losing state
            
            // If removing 1 coin leaves the opponent in a losing state
            if (i - 1 >= 0 && !dp[i - 1]) {
                dp[i] = true;
            }
            // If removing x coins leaves the opponent in a losing state
            else if (i - x >= 0 && !dp[i - x]) {
                dp[i] = true;
            }
            // If removing y coins leaves the opponent in a losing state
            else if (i - y >= 0 && !dp[i - y]) {
                dp[i] = true;
            }
        }
        
        // The result for n coins will be stored in dp[n]
        return dp[n];
    }
};
