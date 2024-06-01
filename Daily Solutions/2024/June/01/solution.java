#### Java

class Solution {
    public static String oddEven(String s) {
        // code here
        int x = 0, y = 0;  // Initialize counters for x and y
        
        // Map to store the frequency of each character in the string
        HashMap<Character, Integer> frequency = new HashMap<>();
        
        // Count the frequency of each character in the string
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            frequency.put(c, frequency.getOrDefault(c, 0) + 1);
        }
        
        // Iterate through the frequency map to compute x and y
        for (HashMap.Entry<Character, Integer> entry : frequency.entrySet()) {
            char character = entry.getKey();
            int freq = entry.getValue();
            int pos = character - 'a' + 1;  // Calculate the position of the character in the alphabet (1-based index)
            
            if ((pos % 2 != 0) && (freq % 2 != 0)) {
                // If the character is in an odd position and has an odd frequency, increment x
                x++;
            } else if ((pos % 2 == 0) && (freq % 2 == 0)) {
                // If the character is in an even position and has an even frequency, increment y
                y++;
            }
        }
        
        // Determine if the summation of x and y is even or odd
        return ((x + y) % 2 != 0) ? "ODD" : "EVEN";
    }
}
