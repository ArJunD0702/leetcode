// Problem: 19. Remove Nth Node From End of List
// Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
// Time Complexity: O(n)
// Memory Complexity: O(1)

#include <stdlib.h>

struct ListNode { //re-defining the struct
    int val;
    struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    if (head == NULL || n <= 0) {
        return head;
    }

    struct ListNode dummy = {0, head};
    struct ListNode *fast = &dummy, *slow = &dummy;

    for (int i = 0; i < n && fast != NULL; ++i) {
        fast = fast->next;
    }
    if (fast == NULL) {
        return head; 
    }

    while (fast->next != NULL) {
        fast = fast->next;
        slow = slow->next;
    }

    struct ListNode *to_delete = slow->next;
    if (to_delete != NULL) {
        slow->next = to_delete->next;
        free(to_delete);
    }

    return dummy.next;
}
