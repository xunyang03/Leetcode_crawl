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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* virtualhead = new ListNode(0);
        virtualhead->next = head;
        ListNode* fast = virtualhead;
        ListNode* slow = virtualhead;

        for (int i = 0; i < n; i++) {
            fast = fast->next;
            if (fast == nullptr)
                return virtualhead->next;
        }
        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* temp = slow->next;
        slow->next = slow->next->next;
        delete temp;

        return virtualhead->next;
    }
};