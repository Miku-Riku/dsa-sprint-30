/*
Title - Reorder List
Link - https://leetcode.com/problems/reorder-list/description/
Date - 06-10-2025
Tags - linked-list, two-pointer, recursion

Time Complexity - 
Space Complexity -

Question - You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.

Solution -
method 1 -->
find mid, store second half in stack
pop one by one and insert in first half

method 2 -->
find mid, reverse second half
then merge two halves  

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
    
    void reorderList(ListNode* head) {
        stack<ListNode*> st;
        ListNode *first = head, *second = head;
        while(second->next && second->next->next){
            first = first->next;
            second = second->next->next;
        }
        ListNode* mid = first->next;
        first->next = NULL;
        while(mid) {
            st.push(mid);
            mid = mid->next;
        }

        ListNode* curr = head;
        while(!st.empty()){
            //main algo
            ListNode* temp = curr->next;
            curr->next = st.top();
            st.top()->next = temp;
            curr = temp;
            st.pop();
        }
        if(curr){
            curr->next = NULL;
        }
        
        return;
    }
};