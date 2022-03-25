// 33. Search in Rotated Sorted Array
// Medium

// There is an integer array nums sorted in ascending order (with distinct values).

// Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].
// Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.
// You must write an algorithm with O(log n) runtime complexity.

// Example 1:
// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4

// Example 2:
// Input: nums = [4,5,6,7,0,1,2], target = 3
// Output: -1

// Example 3:
// Input: nums = [1], target = 0
// Output: -1

// Constraints:

//     1 <= nums.length <= 5000
//     -104 <= nums[i] <= 104
//     All values of nums are unique.
//     nums is an ascending array that is possibly rotated.
//     -104 <= target <= 104


class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        // initialize left, right and mid pointer
        int leftptr{0};
        int rightptr{int(nums.size())-1};
        int midptr{0};
        
        while(leftptr <= rightptr){
            
            // midpoint calculation
            midptr = round((leftptr+rightptr)/2);
            
            // return the index of target if target is found
            if (target == nums[midptr]){
                return midptr;
            }

            // if midpointer is in left sorted array
            if (nums[midptr] >= nums[leftptr]){
                
                // if the target is in left side of the binary tree, remove right tree
                if(target >= nums[leftptr] && target < nums[midptr]){
                    rightptr = midptr - 1;
                }
                 // if target is in right side of the binary tree, remove left tree
                else{
                    leftptr = midptr + 1;
                };
            }
            
            // if midpoint is in right sorted array
            else{
                
                // if the target is in right side of the binary tree, remove left tree
                if(target > nums[midptr] && target <= nums[rightptr]){
                    leftptr = midptr + 1 ;
                }
                // if the target is in left side of the binary tree, remove right tree
                else{
                    rightptr = midptr - 1;
                };
                
                
            };
            
                
        };
        
        return -1;
        
    };
    
    
};
