#### Java

class Solution {
    public int findMinCost(String x, String y, int costX, int costY) {
        
        int m = x.length(); // Length of string x
        int n = y.length(); // Length of string y

        // Create a DP table to store lengths of longest common subsequence (LCS)
        int[][] dp = new int[m + 1][n + 1];

        // Fill the DP table
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (x.charAt(i - 1) == y.charAt(j - 1)) {
                    // If characters match, take diagonal value and add 1
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    // If characters don't match, take the maximum value from left or top cell
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // Length of the longest common subsequence
        int lcsLength = dp[m][n];

        // Calculate the minimum cost
        // (m - lcsLength) gives the number of characters to be deleted from x
        // (n - lcsLength) gives the number of characters to be deleted from y
        int minCost = (m - lcsLength) * costX + (n - lcsLength) * costY;

        return minCost;
       
    }
}