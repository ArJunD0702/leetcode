// Problem: 206. Reversed Linked List
// Link: https://leetcode.com/problems/reverse-linked-list/
// Time Complexity: O(n) 
// Memory Complexity: O(1) 

#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *prev = NULL;
    struct ListNode *cur = head;
    struct ListNode *next = NULL;

    while (cur != NULL) {
        next = cur->next;
        cur->next = prev;

        prev = cur;
        cur = next;
    }

    return prev;
}