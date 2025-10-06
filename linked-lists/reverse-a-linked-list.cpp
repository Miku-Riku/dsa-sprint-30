/*
Title - reverse a linked list
Link -
Date - 06-10-2025
Tags - linked-list, recursion

Time Complexity - O(n)
Space Complexity - O(1) or O(n) depending on the approach

Question -

Solution -

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* solve(ListNode* first, ListNode* second){
        if(second == NULL){
            return first;
        }
        ListNode* temp = second->next;
        second->next = first;
        return solve(second, temp);
    }
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = NULL, *curr = head;
        return solve(prev, head);
        
    }
};