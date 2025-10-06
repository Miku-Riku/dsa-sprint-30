/*
Title - Linked List Cycle
Link - https://leetcode.com/problems/linked-list-cycle/description/
Date - 06-10-2025
Tags - linked-list, two-pointers, floyds-algorithm

Time Complexity - O(N)
Space Complexity - O(1)

Question - detect cycle in the linked list

Solution -
The core concept is, if there is a loop, the fast pointer will eventually meet the slow pointer.
If there is no loop, the fast pointer will reach the end of the linked list before the slow pointer.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) return false;            
        
        // cout << "meow";
        ListNode *first = head, *second = head;
        while(second && second->next){
            // cout << first->val << " " << second->val << endl;
            

            first = first->next;
            second = second->next->next;
            if(first == second) return true;
        }
        return false;
    }
};