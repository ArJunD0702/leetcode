/**
 * Problem: 234 Palindrome Linked List
 * Link: https://leetcode.com/problems/palindrome-linked-list/
 *
 * Approach:
 *   Get both halves of the list. Handle cases for both odd and even
 *   number of nodes. Reverse the second half. Check both halves node-by-node. 
 *   
 * Time Complexity:  O(n)
 * Space Complexity: O(1) 
 */

#include <stdio.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

void reverse(struct ListNode **head) {
    struct ListNode *prev = NULL;
    struct ListNode *cur = *head;
    struct ListNode *next = NULL;

    while (cur) {
        next = cur->next;
        cur->next = prev;
        
        prev = cur;
        cur = next;
    }

    *head = prev;
}

struct ListNode* middle(struct ListNode *head) {
    struct ListNode *slow = head;
    struct ListNode *fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return (fast ? slow->next : slow);
}

bool isPalindrome(struct ListNode* head) {
    struct ListNode *a = head;
    struct ListNode *b = middle(head);

    reverse(&b);
    struct ListNode *p1 = a, *p2 = b;
    while (p2) {
        if (p1->val != p2->val) {
            return false;
        }

        p1 = p1->next;
        p2 = p2->next;
    }

    return true;
}