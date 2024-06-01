#### C++

class Solution {
  public:
    vector<int> constructList(int q, vector<vector<int>> &queries) {
        // code here
        // Vector to store the elements of the list
        vector<int> result;
        result.push_back(0);  // Initially, the list contains only the value 0
        int xor_accumulator = 0;  // Variable to track cumulative XOR operations
    
        // Process each query
        for (const auto &query : queries) {
            int type = query[0];  // Type of query (0 for insertion, 1 for XOR operation)
            int x = query[1];     // Value associated with the query
    
            if (type == 0) {
                // For insertion (0 x), apply the current XOR accumulator to x and add to the list
                result.push_back(x ^ xor_accumulator);
            } else if (type == 1) {
                // For XOR operation (1 x), update the XOR accumulator
                xor_accumulator ^= x;
            }
        }
    
        // Apply the final XOR accumulator to all elements in the list
        for (int &value : result) {
            value ^= xor_accumulator;
        }
    
        // Sort the result list
        sort(result.begin(), result.end());
    
        return result;  // Return the sorted list
        
    }
};
