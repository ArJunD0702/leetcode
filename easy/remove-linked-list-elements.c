// Problem: 203. Remove Linked List Elements
// Link: https://leetcode.com/problems/remove-linked-list-elements/
// Time Complexity: O(n) 
// Memory Complexity: O(1) 

#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode dummy = {0, head};
    struct ListNode *cur = &dummy;

    while (cur->next) {
        if (cur->next->val == val) {
            struct ListNode *temp = cur->next;
            cur->next = temp->next;
            free(temp);
        } 
        else {
            cur = cur->next;
        }
    }

    return dummy.next;
}
