#### Java

class Solution {
    public static int longestSubseq(int n, int[] a) {
        // code here
        if (n == 0) return 0; // If the array is empty, return 0

        int[] dp = new int[n];
        Arrays.fill(dp, 1); // Initialize dp array with 1s, as each element itself is a subsequence

        // Iterate through each element of the array starting from the second element
        for (int i = 1; i < n; ++i) {
            // Compare the current element a[i] with all previous elements a[j]
            for (int j = 0; j < i; ++j) {
                // If the absolute difference between a[i] and a[j] is 1
                if (Math.abs(a[i] - a[j]) == 1) {
                    // Update dp[i] to the maximum of its current value and dp[j] + 1
                    dp[i] = Math.max(dp[i], dp[j] + 1);
                }
            }
        }

        // The length of the longest subsequence will be the maximum value in the dp array
        int maxLength = 0;
        for (int length : dp) {
            if (length > maxLength) {
                maxLength = length;
            }
        }

        return maxLength;
    }
}
