// Title: Kadane's Algorithm for Maximum Subarray Sum
// Link: https://leetcode.com/problems/maximum-subarray/
// Date: 26-06-2025
// time complexity - O(n)
// space complexity - O(1)
// Tags: #Array #DP #Kadane #Leetcode #Medium


// concept - 
//  Choice 1: Extend the maximum sum subarray ending at the previous element by adding the 
//  current element to it. If the maximum subarray sum ending at the previous index is positive, 
//  then it is always better to extend the subarray.

//  Choice 2: Start a new subarray starting from the current element. 
//  If the maximum subarray sum ending at the previous index is negative, 
//  it is always better to start a new subarray from the current element.



#include <iostream>
#include <vector>

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        long long sum = nums[0], temp = nums[0];
        
        for(int i = 1; i < nums.size(); i++){
            if(temp > 0){
                temp += nums[i];
                
            }
            else if (temp <= 0){
                temp = nums[i];
            }
            if(temp > sum){
                sum = temp;
            }
        }
        return sum;
    }
};