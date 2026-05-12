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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL)
            return list2;
        if (list2 == NULL)
            return list1;
        
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;

        ListNode* head = NULL;
        ListNode* tail = NULL;

        if(temp1->val <= temp2->val){
            head = temp1;
            tail = temp1;
            temp1 = temp1->next;
        } else {
            head = temp2;
            tail = temp2;
            temp2 = temp2->next;
        }
        while (temp1 != NULL && temp2 != NULL) {
            if (temp1->val <= temp2->val) {
                tail->next = temp1;
                temp1 = temp1->next;
            } else {
                tail->next = temp2;
                temp2 = temp2->next;
            }

            tail = tail->next;
        }

        // Attach remaining nodes
        if (temp1 != NULL) {
            tail->next = temp1;
        } else {
            tail->next = temp2;
        }

        return head;
    }
};
