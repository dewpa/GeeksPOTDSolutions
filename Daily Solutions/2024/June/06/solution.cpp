class Solution {
  public:
    long long max_sum(int a[], int n) {
        // Your code here
        // s1: Initial sum of i*arr[i] for the original array
        // ts: Total sum of array elements
        long long s1 = 0;
        long long ts = 0;
        
        // Calculate the initial s1 and total sum ts
        for (int i = 0; i < n; i++) {
            s1 += (long long)i * a[i];  // Calculate initial s1 value
            ts += (long long)a[i];      // Calculate total sum of array elements
        }
        
        // Initialize maximum sum with the initial s1 value
        long long maxi = s1;
        
        // Iterate through the array to calculate sum for each rotation
        for (int i = n - 1; i >= 1; i--) {
            // Update s1 for the current rotation
            s1 = s1 + ts - (long long)n * a[i];
            // Update maximum sum if current s1 is greater than the previously recorded maximum sum
            if (maxi < s1) {
                maxi = s1;
            }
        }
        
        // Return the maximum sum found
        return maxi;
    }
};
