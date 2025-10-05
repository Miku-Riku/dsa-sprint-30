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