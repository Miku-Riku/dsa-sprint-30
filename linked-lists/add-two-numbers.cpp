/*
Title - Add Two Numbers
Link - https://leetcode.com/problems/add-two-numbers/description/
Date - 11-10-2025
Tags - Linked List, Math, Recursion

Time Complexity - O(max(m, n)) where m and n are the lengths of the two linked lists.
Space Complexity - O(max(m, n)) for the new linked list.

Question -

Solution -
// pusdo code
        // 1. intialize a new node with resHead
        // 2. we stay in loop till both the l1, l2 are empty
        // 3. if one of it is null, we use it as 0, the other digit will be its digit.
        // 4. we add both digits with carry, we get a result, the unit digit goes to new node and attached to previous one.
        // the tens place goes to carry, we update both l1, l2 pointers.

        // once we exit loop, we see if carry is not zero, then we make new node and add that to this chain
        // else we simply return the newHead

*/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode *newHead = NULL, *curr = NULL;
        newHead = new ListNode();
        curr = newHead;
        int carry = 0, a, b;

        while(l1 || l2){
            if(l1) a = l1->val;
            else a = 0;

            if(l2) b = l2->val;
            else b = 0;

            carry = a + b + carry;
            curr->next = new ListNode(carry%10);
            carry /= 10;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
            curr = curr->next;
        }
        if(carry) {
            curr->next = new ListNode(carry);
        }

        return newHead->next;
    }
};