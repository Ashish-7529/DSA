/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;

        int n = 0;

        while (curr != NULL) {
            n++;
            curr = curr->next;
        }

        if (n % 2 == 0)
            n = n / 2;
        else
            n = n / 2 + 1;

        curr = head;

        for (int i = 1; i <= n; i++) {
            prev = curr;
            curr = curr->next;
        }

        prev->next = NULL;

        curr = reverseList(curr);

        ListNode* l1 = head;
        ListNode* l2 = curr;

        ListNode* currl1 = NULL;
        ListNode* currl2 = NULL;

        while (l1 != NULL && l2 != NULL) {

            currl1 = l1->next;
            currl2 = l2->next;

            l1->next = l2;
            l2->next = currl1;

            l1 = currl1;
            l2 = currl2;
        }
    }

    ListNode* reverseList(ListNode* head) {

        if (head == NULL)
            return NULL;

        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* curr1 = head->next;

        while (curr != NULL) {

            curr->next = prev;
            prev = curr;

            curr = curr1;

            if (curr1 != NULL)
                curr1 = curr1->next;
        }

        return prev;
    }
};