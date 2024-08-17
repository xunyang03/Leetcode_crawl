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
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        int lenA = 0, lenB = 0;
        ListNode* curA = headA;
        ListNode* curB = headB;
        while (curA) {
            curA = curA->next;
            lenA++;
        }
        while (curB) {
            curB = curB->next;
            lenB++;
        }
        if (lenA > lenB) {
            swap(headA, headB);
            swap(lenA, lenB);
        }
        ListNode* dummyHeadA = new ListNode(0);
        ListNode* dummyHeadB = new ListNode(0);
        dummyHeadA->next = headA;
        dummyHeadB->next = headB;
        curA = dummyHeadA;
        curB = dummyHeadB;
        for (int i = 0; i < lenB - lenA; i++) {
            curB = curB->next;
        }
        while (curB) {
            curB = curB->next;
            curA = curA->next;
            if (curA == curB)
                return curA;
        }
        return nullptr;
    }
};