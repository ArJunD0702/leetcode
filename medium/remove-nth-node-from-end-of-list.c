#include <stdio.h>
#include <stdlib.h>

struct ListNode {
      int val;
      struct ListNode *next;
  };

void print_list(struct ListNode *head) {
    struct ListNode *cur = head;
    
    printf("[");
    while (cur != NULL) {
        printf("%d,", cur->val);
        cur = cur->next;
    }
    printf("]\n");
}

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    if (head == NULL) {
        return NULL;
    }

    struct ListNode *fast = head, *slow = fast;
    while (n - 1 > 0) {
        if (fast == NULL) {
            return NULL;
        }
        n--;
        fast = fast->next;
    }

    while (fast != NULL) {
        fast = fast->next;
        slow = slow->next;
    }

    struct ListNode *temp = slow->next;
    slow->next = slow->next->next;
    free(temp);

    print_list(head);
}