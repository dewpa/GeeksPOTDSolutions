#### Java

class Solution {
    static int swapNibbles(int n) {
        // Code to swap nibbles in an integer 'n' and return the result
        return ((n & 0x0F) << 4 | (n & 0xF0) >> 4);
    }
}

class Solution {
    static int swapNibbles(int n) {
        // Code to swap nibbles in an integer 'n' and return the result
        // Extract the higher nibble and lower nibble using bitwise operations
        int higherNibble = (n & 0xF0) >> 4; // Mask the upper 4 bits (higher nibble) and shift them right by 4 bits
        int lowerNibble = (n & 0x0F);       // Mask the lower 4 bits (lower nibble)

        // Swap the positions of the higher and lower nibbles
        // Shift the lower nibble left by 4 bits and OR it with the higher nibble
        int result = (lowerNibble << 4) | higherNibble;

        return result;
    }
}