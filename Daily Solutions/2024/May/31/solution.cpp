#### C++

class Solution {
  public:
    int swapNibbles(int n) {
        // code here
        // Extract the higher nibble and the lower nibble using bitwise operations
        unsigned char higherNibble = (n & 0xF0) >> 4; // Mask the upper 4 bits (higher nibble) and then shift them to the right by 4 bits
        unsigned char lowerNibble = (n & 0x0F);       // Mask the lower 4 bits (lower nibble)
    
        // Swap the positions of the higher and lower nibbles
        // Shift the lower nibble to the left by 4 bits and OR it with the higher nibble
        unsigned char result = (lowerNibble << 4) | higherNibble;
    
        return result;
    }
};

