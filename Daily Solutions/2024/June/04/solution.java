class Solution {
    String binaryNextNumber(String s) {
        // code here.
        StringBuilder sb = new StringBuilder(s);
        int i = sb.length() - 1;

        // Traverse the string from the end and replace '1's with '0's until a '0' is encountered
        while (i >= 0 && sb.charAt(i) != '0') {
            sb.setCharAt(i, '0');
            i--;
        }

        // If all characters were '1's and now the string is all '0's, prepend '1' to the string
        if (i < 0) {
            sb.insert(0, '1');
        } else {
            // Otherwise, replace the first '0' found with '1'
            sb.setCharAt(i, '1');
        }

        // Reverse the string
        sb.reverse();
        
        // Remove trailing '0's from the reversed string
        while (true) {
            int n = sb.length();
            if (sb.charAt(n - 1) == '0') {
                sb.deleteCharAt(n - 1);
            } else {
                break;
            }
        }

        // Reverse the string back to its original order
        sb.reverse();
        return sb.toString();

    }
}
