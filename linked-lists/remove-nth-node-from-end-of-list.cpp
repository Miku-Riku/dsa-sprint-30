/*
Title - Remove Nth Node From End of List
Link - https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
Date - 06-10-2025
Tags - linked-list, two-pointer, dummy-node

Time Complexity - O(N)
Space Complexity - O(1)

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return NULL;
        int numberOfNodes = 0;
        //edge cases
        //single 

        ListNode* curr = head;
        while(curr){
            numberOfNodes++;
            curr = curr->next;
        }
        int index = numberOfNodes - n;

        ListNode* prev = NULL;
        curr = head;
        while(index--){
            prev = curr;
            curr = curr->next;
        }
        if(!prev) head = head->next;
        else prev->next = curr->next;
        return head;
    }
};