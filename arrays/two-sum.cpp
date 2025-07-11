/*
Title : Two Sum
Link : https://leetcode.com/problems/two-sum/description/
Date : 29-06-2025
Tags : #Array #HashMap #TwoSum #Leetcode #Easy

question : 

approach :
1. Create a vector of pairs to store the elements and their original indices.
2. Sort the vector based on the elements.
3. Use two pointers, left and right, to traverse the sorted vector.
4. If the sum of the elements at the left and right pointers is equal to the target,
   return their original indices.
5. If the sum is less than the target, move the left pointer to the right.
6. If the sum is greater than the target, move the right pointer to the left.   

Time Complexity : O(nlogn)
Space Complexity : O(n)



other efficient approaches than above one - 
method -2
1. iterate through array
2. For each element in array, add it to a hash map with its index as itws value and check
if its complement (target - element) exists in the hash map.
3. If it exists, return the indices of the current element and its complement.

Time Complexity : O(n)
Space Complexity : O(n)

Run time - beats 100%
Memory usage - 14.82mb, beats 37.16%

*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:

//method-1
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        vector<pair<int, int>> array(nums.size());
        int count = 0;
        for(int i:nums){
            array[count].first = i;
            array[count].second = count;            
            count++;
        }

        sort(array.begin(), array.end());
        int left = 0, right = nums.size()-1;
        while(left < right){
            if(array[left].first + array[right].first == target){
                ans.push_back(array[left].second);
                ans.push_back(array[right].second);
                break;
            }else if(array[left].first + array[right].first < target){
                left++;
            }else if(array[left].first + array[right].first > target){
                right--;
            }

        }
        return ans;
    }

    //method-2
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans = {};
        unordered_map<int, int> hashMap; // to store the element and its index
        for(int i = 0; i < nums.size(); i++){
            int complement = target - nums[i];
            if(hashMap.find(complement) != hashMap.end()){
                ans.push_back(hashMap[complement]);
                ans.push_back(i);
                return ans;
            }
            hashMap[nums[i]] = i; // store the index of the current element
        }
        return ans; // return empty vector if no solution found
    }
};