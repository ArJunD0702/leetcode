// Problem: 83. Remove Duplicates from Sorted List
// Link: https://leetcode.com/problems/remove-duplicates-from-sorted-list/
// Time Complexity: O(n) 
// Memory Complexity: O(1) 
 

#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode *cur = head;

    while (cur && cur->next) {
        if (cur->val == cur->next->val) {
            struct ListNode *dup = cur->next;
            cur->next = dup->next;
            free(dup);
        } 
        else {
            cur = cur->next;
        }
    }

    return head;
}
