class Solution {
    long findSwapValues(long a[], int n, long b[], int m) {
        //Your code goes here
        // Calculate the sum of elements in array a
        long s1 = 0;
        for (long x : a) {
            s1 += x;
        }
        
        // Calculate the sum of elements in array b
        long s2 = 0;
        for (long x : b) {
            s2 += x;
        }
        
        // If the difference between the sums is not even, return -1
        // because we need an integer value of (s1 - s2) / 2 for a valid pair
        if ((s1 - s2) % 2 != 0) {
            return -1;
        }
        
        // Sort both arrays to use the two-pointer technique
        Arrays.sort(a);
        Arrays.sort(b);
        
        // Calculate the target difference that we need to balance the sums
        long temp = (s1 - s2) / 2;
        
        // Use two pointers to find the pair (a[i], b[j]) such that a[i] - b[j] == temp
        int i = 0, j = 0;
        while (i < n && j < m) {
            long curr = a[i] - b[j];
            
            // If the current difference is equal to the target difference, return 1
            if (curr == temp) {
                return 1;
            }
            
            // If the current difference is less than the target difference, move the pointer in array a
            else if (curr < temp) {
                i++;
            }
            
            // If the current difference is greater than the target difference, move the pointer in array b
            else {
                j++;
            }
        }
        
        // If no such pair is found, return -1
        return -1;
    }
}
