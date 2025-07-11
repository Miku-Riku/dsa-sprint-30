/*\
title : k-most-frequent-elements
Link : https://leetcode.com/problems/k-most-frequent-elements/
Date : 10-07-2025
Tags : #Array #HashMap #BucketSort #Leetcode #Medium

problem : Given an integer array nums and an integer k, return the k most frequent elements. 
You may return the answer in any order.
Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]


Solution
Un-optimal approaches -
So using sort makes problem easy, but takes O(nlogn) time complexity, which is not optimal.

Catch - Th max possible frequency for a element could be only n (size of the input array)

Approach : 
1. So we first use unordered_map to calculate the frequecy of every element
2. then we use a bucket array whose index is frequency and values is all the values that has that
frequency
3. so we iterate through map, and add the values to the bucket array based on its frequency
4. then we iterate through the bucket array in reverse order, and add the values to the final result

Time Compelxity : O(n)
// Space Complexity : O(n)

Run time - beats 100%
Memory - beats 12.74%

*/

// add libraries to eliminate the need to include them individually
#include <bits/stdc++.h>

vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<vector<int>> buckets(nums.size() + 1);
        unordered_map<int, int> m;
        // find frequency of each element in the given array
        for(int x : nums){
            m[x]++;
        }

        // sort the values into buckets based on frequency
        for(auto& x : m){
            // x repreents a pair in the map
            buckets[x.second].push_back(x.first);
        }

        // iterate from last element in buckets array and add values to final 
        // result

        vector<int> ans;
        ans.reserve(k);
        
       
        for(int i = buckets.size()-1; i >= 0; i--){
            for(auto x : buckets[i]){
                if(ans.size() == k){
                    break;
                }
                ans.push_back(x);
                
                
            }
        }

        return ans;


    }