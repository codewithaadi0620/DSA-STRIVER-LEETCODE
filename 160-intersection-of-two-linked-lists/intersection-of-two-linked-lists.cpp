/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int getLength(ListNode* head) {
        int len = 0;
        while (head != NULL) {
            len++;
            head = head->next;
        }
        return len;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = getLength(headA);
        int lenB = getLength(headB);

        ListNode* temp1 = headA;
        ListNode* temp2 = headB;

        int diff = abs(lenA - lenB);

        if (lenA > lenB) {
            while (diff--) {
                temp1 = temp1->next;
            }
        } else {
            while (diff--) {
                temp2 = temp2->next;
            }
        }

        while (temp1 != NULL && temp2 != NULL) {
            if (temp1 == temp2) {
                return temp1;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        return NULL;
    }
};