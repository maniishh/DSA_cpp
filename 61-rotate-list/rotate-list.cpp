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
        if (head == nullptr || head->next == nullptr || k == 0)
            return head;
        int l = 1;
        ListNode* tail = head;
        while (tail->next) {
            l++;
            tail = tail->next;
        }

        k = k % l;
        if (k == 0)
            return head;
        tail->next = head;
        int step = l - k - 1;
        ListNode* newTail = head;
        for (int i = 0; i < step; i++) {
            newTail = newTail->next;
        }
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        // while (k > 0) {
        //     ListNode* last = head;
        //     ListNode* secLast = nullptr;
        //     while (last->next != nullptr) {
        //         secLast = last;
        //         last = last->next;
        //     }
        //     secLast->next = nullptr;
        //     last->next = head;
        //     head = last;
        //     k--;
        // }

        return newHead;
    }
};