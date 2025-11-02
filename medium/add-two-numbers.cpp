/**
 * Problem: 2. Add Two Numbers 
 * https://leetcode.com/problems/add-two-numbers/
 *
 * Approach:
 *   Traverse both linked lists simultaneously, adding corresponding values
 *   along with carry. Add 0 when a list has fewer nodes. Append final carry.
 *
 * Time Complexity:  O(max(n, m))
 * Space Complexity: O(1) extra
 */

struct ListNode { // re-defining the struct
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode *cur = &dummy;

        int carry = 0;
        while (l1 || l2 || carry) {
            int val1 = (l1 ? l1->val : 0);
            int val2 = (l2 ? l2->val : 0);

            int sum = val1 + val2 + carry;
            carry = sum / 10;

            cur->next = new ListNode(sum % 10);
            cur = cur->next;

            if (l1) {
                l1 = l1->next;
            }
            if (l2) {
                l2 = l2->next;
            }
        }

        return dummy.next;
    }
};