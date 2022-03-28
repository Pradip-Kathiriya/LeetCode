# 338. Counting Bits
# Easy

# Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.

# Example 1:
# Input: n = 2
# Output: [0,1,1]
# Explanation:
# 0 --> 0
# 1 --> 1
# 2 --> 10

# Example 2:

# Input: n = 5
# Output: [0,1,1,2,1,2]
# Explanation:
# 0 --> 0
# 1 --> 1
# 2 --> 10
# 3 --> 11
# 4 --> 100
# 5 --> 101

# Constraints:

#     0 <= n <= 105

# Follow up:
#     It is very easy to come up with a solution with a runtime of O(n log n). Can you do it in linear time O(n) and possibly in a single pass?
#     Can you do it without using any built-in function (i.e., like __builtin_popcount in C++)?

class Solution(object):
    def countBits(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        result = [0]*(n+1) # variable to store final result
        significant_digit = 1 # flag where pattern of 1's and 0's get repeated in 
                              # binary space i.e 0,1,2,4,8,16...
        
        for i in range(1, n+1):
            
            # update significant digit 
            if significant_digit *2 == i:
                significant_digit = i
                
            # find the number of 1 in binary representation of digit
            result[i] = 1 + result[i-significant_digit]
        
        return result