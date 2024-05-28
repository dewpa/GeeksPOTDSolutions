#### C++

class Solution {
  public:
    int minimumCost(int n, int w, vector<int> &cost) {
        // code here
        // Initialize dp array with infinity (INT_MAX)
        vector<int> dp(w + 1, INT_MAX);
        // Cost to buy 0 kg is 0
        dp[0] = 0;
    
        // Iterate over all possible weights from 1 to w
        for (int j = 1; j <= w; ++j) {
            // Check all packet sizes that can contribute to the weight j
            for (int i = 1; i <= n; ++i) {
                // If the packet is available and can be used
                if (i <= j && cost[i-1] != -1) {
                    // If dp[j - i] is not infinity, update dp[j]
                    if (dp[j - i] != INT_MAX) {
                        dp[j] = min(dp[j], dp[j - i] + cost[i-1]);
                    }
                }
            }
        }
    
        // If dp[w] is still infinity, it means we cannot form weight w
        return dp[w] == INT_MAX ? -1 : dp[w];
    }
};
