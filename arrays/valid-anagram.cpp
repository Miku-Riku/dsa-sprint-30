/*
Title: valid-Anagram
// Link: https://leetcode.com/problems/valid-anagram/
// Date: 29-06-2025
// Tags: #Array #HashSet #Leetcode #Easy

question - Given two strings s and t, return true if t is an anagram of s, and false otherwise.
solution - We can solve this problem using hashing of all 26 characters to keep track of the 
elements we have seen so far.

time complexity - O(n+m), where n,m is the length of the string s and t respectively.
space complexity - O(1), since we are using a fixed size array of 26 characters
*/

#include <vector>
#include <string>
#include <iostream>
using namespace std;



class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> v(26, 0);
        for(char c : s){
            v[c-'a']++;
        }
        for(char c : t){
            if(v[c-'a'] > 0){
                v[c-'a']--;
            }else{
                return false;
            }
        }
        for(int c : v){
            if(v[c] != 0){
                return false;
            }
        }
        return true;
    }
};