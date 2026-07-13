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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==0) return head;
        ListNode* s=head;
        int l=0;
        while(s){
            l++;
            s=s->next;
        }
        k=k%l;
        if(k==0) return head;
        l=l-k;
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* newHead=NULL;
        while(curr){
           if(l==0){
            prev->next=NULL;
            newHead=curr;
           }
           prev=curr;
           curr=curr->next;
           l--;
        }prev->next=head;
        return newHead;

    }
};