/*
Title - Trapping Rain Water
Link -
Date - 05-10-2025
Tags - #Arrays #TwoPointers

Time Complexity - O(n)
Space Complexity - O(1)

Question - Given n non-negative integers representing an elevation map where the width 
of each bar is 1, compute how much water it can trap after raining.

Solution -
Method - 1
Intution --> Each index can trap water upto the minimum of maximum height of bars on its left 
and right side. 

Brute Force -> so we find, for each index i, the maximum height of bar on its left side (left_max) and
the maximum height of bar on its right side (right_max). and find the value

Method 2 -->
Making left max and right max arrays for each index, u can easily find it, but takes O(n) space.

Method 3 --> two pointer approach


*/

class Solution {
public:
    int trap(vector<int>& height) {
        int leftMax = height[0], rightMax = height[height.size()-1], left = 0, right = height.size()-1;
        int trappedWater = 0;
        if(height[left] <= height[right]) left++;
        else right--;

        while(left <= right){
            if(height[left] <= height[right]){
                if(height[left] > leftMax) {
                    leftMax = height[left];
                }else {
                    trappedWater += (leftMax - height[left]);
                }
                left++;
            }
            else if (height[left] > height[right]){
                if(height[right] > rightMax) {
                    rightMax = height[right];
                }else {
                    trappedWater += (rightMax - height[right]);
                }
                right--;
            }
        }
        return trappedWater;
    }
};