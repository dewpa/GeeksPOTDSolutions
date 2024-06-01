#### C++

class Solution {
  public:
    string oddEven(string s) {
        // code here
        int x = 0, y = 0;  // Initialize counters for x and y
    
        // Map to store the frequency of each character in the string
        unordered_map<char, int> frequency;
        
        // Count the frequency of each character in the string
        for (int i = 0; i < s.size(); i++) {
            frequency[s[i]]++;
        }
        
        // Iterate through the frequency map to compute x and y
        for (auto it : frequency) {
            int pos = it.first - 'a' + 1;  // Calculate the position of the character in the alphabet (1-based index)
            
            if ((pos & 1) && (it.second & 1)) {
                // If the character is in an odd position and has an odd frequency, increment x
                x++;
            } else if (!(pos & 1) && !(it.second & 1)) {
                // If the character is in an even position and has an even frequency, increment y
                y++;
            }
        }
        
        // Determine if the summation of x and y is even or odd
        return ((x + y) & 1) ? "ODD" : "EVEN";
    }
};
