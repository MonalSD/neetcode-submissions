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
        unordered_map<Node*,Node*> old;
        old[NULL]=NULL;
        Node* curr = head;

        while(curr!=NULL){
            Node* copy = new Node(curr->val);
            old[curr] = copy;
            curr = curr->next;
        }

        curr = head;
        while(curr!=NULL){
            Node* copy = old[curr];
            copy->next = old[curr->next];
            copy->random = old[curr->random];
            curr = curr->next;
        }

        return old[head];

    }
};
