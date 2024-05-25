#### C++

class Solution {
  public:
    /*You are requried to complete this method */
    long long max_Books(int arr[], int n, int k) {
        // Your code here
        int left = 0; // Initialize the left pointer of the sliding window
        int right = 0; // Initialize the right pointer of the sliding window
        long long currentSum = 0; // To store the sum of books in the current window
        long long maxBooksCollected = 0; // To store the maximum number of books collected

        // Loop until the right pointer reaches the end of the array
        while (right < n) {
            // Check if the height of the stack at the right pointer is less than or equal to k
            if (arr[right] <= k) {
                // If it is, add the height to the current sum
                currentSum += arr[right];
                // Update the maximum books collected if the current sum is greater
                maxBooksCollected = max(maxBooksCollected, currentSum);
                // Move the right pointer to the next position to expand the window
                right++;
            } else {
                // If the height of the stack at the right pointer exceeds k,
                // reset the current sum to 0
                currentSum = 0;
                // Move the right pointer to the next position to start a new window
                right++;
                // Move the left pointer to the right pointer to start a new window
                left = right;
            }
        }

        // Return the maximum number of books collected
        return maxBooksCollected;
    }
};