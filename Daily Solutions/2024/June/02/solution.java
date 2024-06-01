#### Java

class Solution {
    public static ArrayList<Integer> constructList(int q, int[][] queries) {
        // code here
        // List to store the elements of the list
        ArrayList<Integer> result = new ArrayList<>();
        result.add(0);  // Initially, the list contains only the value 0
        int xorAccumulator = 0;  // Variable to track cumulative XOR operations

        // Process each query
        for (int i = 0; i < q; i++) {
            int type = queries[i][0];  // Type of query (0 for insertion, 1 for XOR operation)
            int x = queries[i][1];     // Value associated with the query

            if (type == 0) {
                // For insertion (0 x), apply the current XOR accumulator to x and add to the list
                result.add(x ^ xorAccumulator);
            } else if (type == 1) {
                // For XOR operation (1 x), update the XOR accumulator
                xorAccumulator ^= x;
            }
        }

        // Apply the final XOR accumulator to all elements in the list
        for (int i = 0; i < result.size(); i++) {
            result.set(i, result.get(i) ^ xorAccumulator);
        }

        // Sort the result list
        Collections.sort(result);

        return result;  // Return the sorted list
    }
}