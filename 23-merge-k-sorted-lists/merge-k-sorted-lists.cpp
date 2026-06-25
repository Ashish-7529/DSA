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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> v;
        for (int i = 0; i < lists.size(); i++) {
            ListNode* temp = lists[i];

            while (temp != nullptr) {
                v.push_back(temp->val);
                temp = temp->next;
            }
        }
        sort(v.begin(), v.end());
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        for (int x : v) {
            temp->next = new ListNode(x);
            temp = temp->next;
        }

        return dummy->next;
    }
};