# 11. Container With Most Water
# Medium

# You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
# Find two lines that together with the x-axis form a container, such that the container contains the most water.
# Return the maximum amount of water a container can store.
# Notice that you may not slant the container.


# Example 1:
# Input: height = [1,8,6,2,5,4,8,3,7]
# Output: 49
# Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

# Example 2:
# Input: height = [1,1]
# Output: 1

# Constraints:
#     n == height.length
#     2 <= n <= 105
#     0 <= height[i] <= 104

class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        leftptr, rightptr = 0, len(height)-1 # left and right pointer to store index of element of height
        area = 0  # variable to store the maximum amount of water
        
        # move the pointer till leftptr crosses righpointer
        while leftptr < rightptr:
            
            # find the side of container having minimum height
            minHeight = min(height[leftptr], height[rightptr])
            
            # update the area
            area = max(area,(rightptr-leftptr)*minHeight)
            
            # if left pointer is pointing to minimum side of container,
            # move the left pointer to find next maximum height
            if minHeight == height[leftptr]:
                leftptr += 1
                while height[leftptr] < minHeight and leftptr < rightptr:
                    leftptr += 1
            
            # if right pointer is pointing to minimum side of container,
            # move the right pointer to find next maximum height        
            if minHeight == height[rightptr]:
                rightptr -= 1
                while height[rightptr] < minHeight and leftptr < rightptr:
                    rightptr -= 1

        return area