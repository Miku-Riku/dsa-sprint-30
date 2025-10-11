/*
Title - Copy List with Random Pointer
Link - https://leetcode.com/problems/copy-list-with-random-pointer/description/
Date - 11-10-2025
Tags - linked-list

Time Complexity - O(n)
Space Complexity - O(1)

Question - create a deep copy of a linked list where each node has a random pointer in 
addition to the next pointer.

Solution -
Trick - create new nodes and attach them to the original nodes, then set the random pointers
of the new nodes, and finally separate the two lists.

*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        
        // Step 1: Create interleaved nodes
        Node* curr = head;
        while(curr){
            Node* newNode = new Node(curr->val);
            newNode->next = curr->next;
            curr->next = newNode;
            curr = newNode->next;
        }
        
        // Step 2: Assign random pointers
        curr = head;
        while(curr){
            if(curr->random) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        // Step 3: Separate the lists
        curr = head;
        Node* newHead = head->next;
        Node* copy = newHead;
        
        while(curr){
            curr->next = copy->next;
            curr = curr->next;
            if(curr){
                copy->next = curr->next;
                copy = copy->next;
            }
        }

        return newHead;
    }
};