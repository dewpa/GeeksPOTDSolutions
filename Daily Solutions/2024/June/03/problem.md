# Problem of the Day - June 03, 2024

## Title : Trail of ones

### Problem Description

Given a number n, find the number of binary strings of length n that contain consecutive 1's in them. Since the number can be very large, return the answer after modulo with 1e9+7.

### Your Task

You don't need to read input or print anything. Your task is to complete the function numberOfConsecutiveOnes() which takes an integer n and returns the number of binary strings that contain consecutive 1's in them.

### Time and Auxiliary Space Complexity

Expected Time Complexity: O(n) \
Expected Space Complexity: O(n)

### Constraints

2 <= n <= 10^5

**Examples**

Example 1:
```
Input: n = 2
Output: 1
Explanation: There are 4 strings of length 2, the strings are 00, 01, 10, and 11. Only the string 11 has consecutive 1's.

```

Example 2:
```
Input: n = 5
Output: 19
Explanation: There are 19 strings having consecutive 1's.

```


