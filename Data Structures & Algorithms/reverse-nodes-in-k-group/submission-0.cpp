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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || k == 1) return head;

        ListNode* kth = head;
        // Find kth node
        for (int i = 1; i < k; i++) {
            if (kth == NULL) 
                return head;
            kth = kth->next;
        }
        // If less than k nodes exist
        if (kth == NULL) 
            return head;
        // right part starts after kth node
        ListNode* rightHead = kth->next;

        // Cut left batch
        kth->next = NULL;

        // Reverse left batch
        ListNode* newHead = reverse(head);

        // After reversal, original head becomes tail
        head->next = reverseKGroup(rightHead, k);

        return newHead;

    }

    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* temp = NULL;
        while(curr!=NULL){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        head = prev;
        return head;
    }
};
