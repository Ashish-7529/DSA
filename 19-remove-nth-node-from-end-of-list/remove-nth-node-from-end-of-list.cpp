/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode() : val(0), next(nullptr) {}
 * ListNode(int x) : val(x), next(nullptr) {}
 * ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       ListNode dummy(0);
       dummy.next = head;
       
       ListNode* slow = &dummy;
       ListNode* fast = &dummy;
       for(int i = 0 ; i < n + 1 ; i++){
           fast = fast->next;
       }
       while(fast){
           slow = slow->next;
           fast = fast->next;
       }
       ListNode* target = slow->next;
       slow->next = target->next;
       target->next = nullptr;
       delete target;
       
       return dummy.next;
    }
};