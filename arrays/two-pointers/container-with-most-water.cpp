/*
Title - Container With Most Water
Link - https://leetcode.com/problems/container-with-most-water/
Date - 04-10-2025
Tags - #Arrays #TwoPointers #Leetcode #Medium

Time Complexity - O(n)
Space Complexity - O(1)

Question - You are given an integer array height of length n. There are n vertical lines 
drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
Find two lines that together with the x-axis form a container, such that the container 
contains the most water.
Return the maximum amount of water a container can store.

Solution -

Brute Force Approach -
A simple approach is to check for every pair of lines and calculate the area formed by them.
track Min area for every pair and return the max area. O(n^2) time complexity

Optimal Approach -
The intution is
For max area --> length and breadth should be max
So we start with max length, that is start and end of the array
we will keep moving the small length height, to find a possibly larger height

*/



class Solution {

public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size()-1, small = INT_MIN;
        int maxAr = INT_MIN;

        while(l < r){
            if(small < min(height[l], height[r])){
                int area = (r-l)*min(height[l], height[r]);
                if(maxAr < area) maxAr = area;
                small = min(height[l], height[r]);

            }
            if(height[l] <= height[r]){
                l++;
                
            }else {
                r--;
                
            }
        }
        return maxAr;
    }
};