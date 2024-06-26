# Problem of the Day - May 23, 2024

## Title : K-Palindrome

### Problem Description

Given a string 'str' of length 'n', find if the string is K-Palindrome or not. A k-palindrome string transforms into a palindrome on removing at most k characters from it. 

### Your Task

You do not need to read input or print anything. Your task is to complete the function kPalindrome() which takes string str, n, and k as input parameters and returns 1 if str is a K-palindrome else returns 0.

### Time and Auxiliary Space Complexity

Expected Time Complexity: O(n*n) \
Expected Auxiliary Space: O(n*n)

### Constraints

1 ≤ n, k ≤ 103

**Examples**

Example 1:
```
Input:
str = "abcdecba"
n = 8, k = 1
Output: 1
Explanation: By removing 'd' or 'e' we can make it a palindrome.

```

Example 2:
```
Input:
str = "abcdefcba"
n = 9, k = 1
Output: 0
Explanation: By removing a single character we cannot make it a palindrome.

```
