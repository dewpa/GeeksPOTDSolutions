class Solution {
  public:
    string binaryNextNumber(string s) {
        // code here.
        int i = s.size() - 1;

    // Traverse the string from the end and replace '1's with '0's until a '0' is encountered
    while (i >= 0 && s[i] != '0') {
        s[i] = '0';
        i--;
    }

    // If all characters were '1's and now the string is all '0's, prepend '1' to the string
    if (i < 0) {
        s = '1' + s;
    } else {
        // Otherwise, replace the first '0' found with '1'
        s[i] = '1';
    }

    // Reverse the string
    reverse(s.begin(), s.end());

    // Remove trailing '0's from the reversed string
    while (true) {
        int n = s.size();
        if (s[n - 1] == '0') {
            s.pop_back();
        } else {
            break;
        }
    }

    // Reverse the string back to its original order
    reverse(s.begin(), s.end());
    return s;
    }
};
