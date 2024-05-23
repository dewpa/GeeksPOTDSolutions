#### Java

```

class Solution {
    
    public int kPalindrome(String str, int n, int k) {
        
        // Create a DP array to store lengths of palindromic subsequences
        int[] dp = new int[n + 1];
        Arrays.fill(dp, 0); // Initialize with zeros

        // Loop through each character from the start of the string
        for (int i = 1; i <= n; ++i) {
            int prev = 0; // To store the value of dp[j-1] from the previous iteration
            for (int j = 1; j <= n; ++j) {
                int temp = dp[j]; // Temporarily store current dp[j] before updating
                if (str.charAt(i - 1) == str.charAt(n - j)) {
                    // If characters match, extend the palindromic subsequence
                    dp[j] = prev + 1;
                } else {
                    // If characters do not match, keep the longest subsequence so far
                    dp[j] = Math.max(dp[j], dp[j - 1]);
                }
                prev = temp; // Update prev for the next comparison
            }
        }

        // The length of the Longest Palindromic Subsequence
        int lps = dp[n];
        // Calculate the minimum deletions needed to make the string a palindrome
        int minDeletions = n - lps;
        // Check if the minimum deletions are within the allowed limit k
        return minDeletions <= k ? 1 : 0;
        
    }
}
		
```