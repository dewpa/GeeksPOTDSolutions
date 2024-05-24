#### C++

class Solution {
  public:
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        const int MOD = 1000000007;
        
        // Calculate the total sum of the array
        int totalSum = 0;
        for (int num : arr) {
            totalSum += num;
        }
        
        // Check if (totalSum + d) is odd or if the required sum S1 is negative
        if ((totalSum + d) % 2 != 0 || totalSum < d) {
            return 0;
        }
        
        // Calculate the required sum S1
        int S1 = (totalSum + d) / 2;
        
        // Initialize the dp array
        vector<int> dp(S1 + 1, 0);
        dp[0] = 1;  // There's one way to get sum 0 - using no elements
        
        // Fill the dp array
        for (int num : arr) {
            for (int j = S1; j >= num; j--) {
                dp[j] = (dp[j] + dp[j - num]) % MOD;
            }
        }
        
        // Return the count of subsets with sum equal to S1
        return dp[S1];
    }
};