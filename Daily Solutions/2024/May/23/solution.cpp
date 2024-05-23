#### C++

```
class Solution {
public:
    int kPalindrome(string str, int n, int k) {
        // Initialize a DP array of size n+1 with 0s
        vector<int> dp(n + 1, 0);

        // Loop through each character in the string
        for (int i = 1; i <= n; ++i) {
            int prev = 0; // Variable to store the value of dp[j-1] from the previous iteration
            for (int j = 1; j <= n; ++j) {
                int temp = dp[j]; // Temporary storage for dp[j] to update prev in the next iteration
                if (str[i - 1] == str[n - j]) {
                    // Characters match, extend the palindromic subsequence
                    dp[j] = prev + 1;
                } else {
                    // Characters do not match, take the maximum value to keep the LPS
                    dp[j] = max(dp[j], dp[j - 1]);
                }
                prev = temp; // Update prev for the next iteration
            }
        }

        // The length of the Longest Palindromic Subsequence
        int lps = dp[n];
        // Calculate the minimum number of deletions required to make the string a palindrome
        int minDeletions = n - lps;
        // Check if the minimum deletions are within the allowed limit k
        return minDeletions <= k ? 1 : 0;
    }
};

```

