// Problem: 141. Linked List Cycle
// Link: https://leetcode.com/problems/linked-list-cycle/
// Time Complexity: O(n) 
// Memory Complexity: O(1) 

#include <stdio.h>
#include <stdbool.h>

struct ListNode {
     int val;
     struct ListNode *next;
};

bool hasCycle(struct ListNode *head) {
    struct ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;

        if (slow == fast) {
            return true;
        }
    }

    return false;
}