/*
// Title: Contains Duplicate
// Link: https://leetcode.com/problems/contains-duplicate/description/
// Date: 28-06-2025
// Tags: #Array #HashSet #Leetcode #Easy

question - Given an integer array nums, return true if any value appears at least twice in the array,
 and return false if every element is distinct.

 solution - We can solve this problem using a hash set to keep track of the elements we have seen so far.
 If we encounter an element that is already in the set, we return true. If we finish iterating through 
 the array without finding any duplicates, we return false.
*/



#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for(int x : nums){
            if(s.count(x)){
                return true;
            }
            s.insert(x);

        }
        return false;
    }
};

// we use set instead of map, because we only need to check for one element
// in map there should be a key-value pair, but in set we only need to check for the key.
// which reduces the time complexity to O(n) and space complexity to O(n) as well.