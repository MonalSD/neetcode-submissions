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
        if (lists.empty()) return NULL;

        ListNode* result = NULL;

        for (int i = 0; i < lists.size(); i++) {
            result = mergeTwoLists(result, lists[i]);
        }

        return result;
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL)
            return l2;

        if (l2 == NULL)
            return l1;

        ListNode* temp1 = l1;
        ListNode* temp2 = l2;

        ListNode* head = NULL;
        ListNode* tail = NULL;

        if (temp1->val <= temp2->val) {
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

        if (temp1 != NULL) {
            tail->next = temp1;
        } else {
            tail->next = temp2;
        }

        return head;
    }
};
