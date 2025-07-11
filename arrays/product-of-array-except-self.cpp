
/*
Title : Product of Array Except Self
Link : https://leetcode.com/problems/product-of-array-except-self/
Date : 10-07-2025
Tags : #Array #PrefixSum #PostfixSum #Leetcode #Medium

question - Given an integer array nums, return an array answer such that answer[i] is equal to the 
product of all the elements of nums except nums[i].
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer


solution - 
un-optimized ones - 
1. we create left and right aarray of same size as input array
2. we store the cumulative product of elemets from left side in left array exclusing the current element
3. simialrly for right arrau
4. so like - 
        [1, 2, 3, 4, 5, 6, 7] - input
        -------->[]<---------
        left array  right array
        product      product
    left = [1, 1, 2, 6, 24, 120, 720]
    right = [5040, 720, 120, 24, 6, 2, 1, 1]
5. now we can just multiply the left and right array to get the answer array.


optimized ones - 
1. we do both operators on ans array itself
2. we will first store the left product in ans array
3. then we will use a variable to store the cumulative product from right side and multiply 
it with ans array

time complexity - O(n)
Space complexity - O(1) (excluding output array)

run time - beats 100%
Memory usage - beats 94%
*/



#include <vector>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
        // other than output array we cant take any auxiliary space as
        //function of input .
        int n = nums.size();
        if(n == 1){
            return {1};
        }
        vector<int> ans(n);
        ans[0] = 1;
        
        //we will make left product in result array itelf

        for(int i = 1; i <= n -1; i++){
            ans[i] = ans[i-1]*nums[i-1];
        }

        // we will multiply things from right side, by storing, the 
        // cummulative multiplication value fromm right side.
        int postfix = 1;
        for(int i = n-2; i>= 0; i--){
            postfix *= nums[i+1];
            ans[i] *= postfix;
        }

        
        return ans;

    }