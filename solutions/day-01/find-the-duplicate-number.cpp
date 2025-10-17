/*
___________________________________________________________________
LeetCode #287 : Find the Duplicate Number                                                   
Difficulty: Medium                                              
Date: 15-10-2025                                                
Tags: #Array #TwoPointers #BinarySearch #BitManipulation                           
Time Complexity: O(n)                                                  
Space Complexity: O(1)                                               
___________________________________________________________________     

PROBLEM:
--------
Given an array of integers nums containing n + 1 integers where each integer is in the 
range [1, n] inclusive.
There is only one repeated number in nums, return this repeated number.
You must solve the problem without modifying the array nums and using only constant extra space.

APPROACH: 
----------------------------
1. Index Sort - O(n)
    We can use the input array itself to place each number at its correct index.

2. Mark visited value within the array - (if modifying the input array is allowed) - O(n)
    We can mark the visited numbers by negating the value at the index corresponding to the number.
    If the value at the index is already negative, then we have found the duplicate number.




KEY INSIGHTS:
-------------
- The problem can be solved using various approaches, each with its own trade-offs in terms of time 
and space complexity.
- Marking visited value within the array is a clever way to track duplicates without extra space.
Its the least confusing and most efficient approach. But only used if there is no constraint on
modifying the input array.

*/


// Code - Mark visited value within the array
int findDuplicate(vector<int>& nums) {
    for(int x = 0; x < nums.size(); x++){
        int val = nums[x];
        if(val-1 < nums.size() && nums[val-1] < 0){
            return val;
        }
        nums[val-1] = -nums[val-1] ;
    }
    return 0;
}

//Code - Index Sort
class Solution {
public:
    void swap(vector<int>& nums, int a, int b){
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
    }
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        while(i < n){
            if (nums[i] < i+1) return nums[i];
            else if (nums[i] == i + 1) i++;
            else if (nums[i] > i+1) {
                if(nums[i] == nums[nums[i]-1]) return nums[i];
                swap(nums, i, nums[i]-1);

            }
        }
        return nums[n-1];
    }
};

