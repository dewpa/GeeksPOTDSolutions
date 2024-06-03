#### C++

class Solution {
  public:
    int numberOfConsecutiveOnes(int n) {
        // code here
        int MOD = 1000000007;
        if (n == 0) return 0;

        // Initialize dp arrays
        vector<long long> dp0(n + 1, 0); // dp0[i] will store the count of valid binary strings of length i ending with 0
        vector<long long> dp1(n + 1, 0); // dp1[i] will store the count of valid binary strings of length i ending with 1
    
        // Base cases
        dp0[1] = 1; // There's 1 binary string of length 1 ending with 0: "0"
        dp1[1] = 1; // There's 1 binary string of length 1 ending with 1: "1"
    
        // Fill dp arrays using the recurrence relations
        for (int i = 2; i <= n; i++) {
            dp0[i] = (dp0[i - 1] + dp1[i - 1]) % MOD; // Strings ending with 0 can be formed by adding 0 to strings ending with either 0 or 1
            dp1[i] = dp0[i - 1] % MOD; // Strings ending with 1 can only be formed by adding 1 to strings ending with 0
        }
    
        // Total strings without consecutive 1s
        long long noConsec1 = (dp0[n] + dp1[n]) % MOD; // Sum of strings of length n ending with either 0 or 1
    
        // Total possible binary strings of length n
        long long totalStrings = 1;
        for (int i = 0; i < n; i++) {
            totalStrings = (totalStrings * 2) % MOD; // Total possible strings of length n is 2^n
        }
    
        // Strings with consecutive 1s
        long long withConsec1 = (totalStrings - noConsec1 + MOD) % MOD; // Subtracting noConsec1 from totalStrings gives strings with consecutive 1s
    
        return withConsec1;
    }
};
