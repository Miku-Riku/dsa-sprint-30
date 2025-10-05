/*
Title - merging two sorted linked lists
Link - https://leetcode.com/problems/merge-two-sorted-lists/description/
Date - 06-10-2025
Tags - Linked List, Recursion

Time Complexity - O(n + m) where n and m are the lengths of the two linked lists.
Space Complexity - O(1) for the iterative approach, O(n + m) for the recursive approach due to call stack.

Question -

Solution -
Method 1: Iterative Approach
We use a head and tail to keep track of our merged list.
whatever is smaller in current list, we add it to the tail of the merged list.

Method 2: Recursive Approach
We divide the problem into smaller same subproblems.
That is, we compare the current value of both list, and return which is smaller.

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head = NULL, *tail = NULL;
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;

        while(list1 && list2){
            if(list1->val <= list2->val){
                ListNode* temp = list1->next;
                if(head == NULL){
                    head = list1;
                    tail = list1;
                }else {
                    tail->next = list1;
                    tail = tail->next;
                }
                list1 = temp;
            }else if(list1->val > list2->val){
                ListNode* temp = list2->next;
                if(head == NULL){
                    head = list2;
                    tail = list2;
                }else{
                    tail->next = list2;
                    tail = tail->next;
                }
                list2 = temp;
            }
        }

        if(list1 == NULL){
            tail->next = list2;
        }else if(list2 == NULL){
            tail->next = list1;
        }
        return head;


    }
};