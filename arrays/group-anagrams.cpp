/*
Title : Group Anagrams
Link : https://leetcode.com/problems/group-anagrams/
Date : 01-07-2025
Tags : #Array #HashMap #Leetcode #Medium

Time complexity : O(n * m * log(m)), where n is the number of strings and m is the maximum length of a string.
Space complexity : O(n * m), where n is the number of strings and m is the maximum length of a string.

Question - Given an array of strings strs, group the anagrams together. You can return the answer in any order.
Solution - 

Different methods that i tried : 

Method - 1 
1. I made a array of hasmap to sstore the count of each letter in the string corresponding
to each sub-list in the final answer
2. So we group anagrams together into different lists in final vector,
3. every time i iterate through a string, i compared it with every sub-list letter count.
4. if it matches, i added it to the list it belongs to in final vector, or i made new list and appended
it to the final vector and added its letter count to the hashmap
5. so basically i mapped letter count to each sub-list
6. each sublist corresponds to an anagram which contain unique letter count

---> takes very high time complexity, so i had to change my approach

method 2 - 
1. In every iteration of a tthe vector<string>, i sorted each string and used it as key to store in 
a hashmap
2. since all the anagrams will have same key, and i can group them together
3. so its like, for every sublist, the sorted string will be the same, so i mapped a sorted string
to a set of strings and added thee each list corresponsing to a sorted anagram to final vector.

method 3 -
1. i did similar thing as in method 2, but instead i didnt store all strings of sorted anagram as its
value
2. But instead i stored only the index od the sublist it belogns in final vector
3. its like, each sorted anagram, will correspond to a sublist, and any string that sortes to a anagram
I stored, at which index in sublist of final vector it belongs to and pushed it in there immediately.



*/

#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;


class Solution {
public:
    

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> m;

        vector<vector<string>> ans;
        for(int i =0; i < strs.size(); i++){
            // not new anagram, already a list is there
            string s = strs[i];
            sort(strs[i].begin(), strs[i].end());
            if(m.find(strs[i]) == m.end()){
                // new anagram
                ans.push_back({});
                m[strs[i]] = (ans.size())-1;
                
            }  
            ans[m[strs[i]]].push_back(s);            
            
        }
        
        return ans;
        
    }
};