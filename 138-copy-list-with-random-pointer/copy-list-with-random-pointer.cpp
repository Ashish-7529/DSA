/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        unordered_map<Node*, Node*>mpp;

        Node* mover = head->next;
        Node* newHead = new Node(head->val);

        mpp[NULL] = NULL;
        mpp[head] = newHead;

        while(mover) {
            mpp[mover] = new Node(mover->val);
            mover = mover->next;
        }

        Node* curr = head;

        while(curr) {
            mpp[curr]->next = mpp[curr->next];
            mpp[curr]->random = mpp[curr->random];
            curr = curr->next;
        }

        return newHead;
    }
};