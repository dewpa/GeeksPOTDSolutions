class Solution {
  public:
    int findSwapValues(int a[], int n, int b[], int m) {
        // Your code goes here
        // Calculate the sum of elements in array a
        int sumA = accumulate(a, a + n, 0);
        // Calculate the sum of elements in array b
        int sumB = accumulate(b, b + m, 0);
    
        // If the difference between the sums is not even, return -1
        // because we need an integer value of (sumA - sumB) / 2 for a valid pair
        if ((sumA - sumB) % 2 != 0) {
            return -1;
        }
    
        // Calculate the target difference
        int target = (sumA - sumB) / 2;
    
        // Use an unordered set to store elements of array a
        unordered_set<int> setA(a, a + n);
    
        // Iterate through each element in array b
        for (int i = 0; i < m; ++i) {
            // Check if there exists an element in array a such that
            // swapping a[i] with b[j] will balance the sums
            if (setA.count(b[i] + target)) {
                return 1;
            }
        }
    
        // If no such pair is found, return -1
        return -1;
    }
};
