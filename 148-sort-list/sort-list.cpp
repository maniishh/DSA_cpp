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
    ListNode* mergeL(ListNode* f, ListNode* sec) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        while (f!=nullptr && sec!=nullptr) {
            if (f->val <= sec->val) {
                tail->next = f;
                f = f->next;
            } else {
                tail->next = sec;
                sec = sec->next;
            }
            tail = tail->next;
        }
        tail->next = (f!=nullptr) ? f : sec;
        return dummy.next;
    }
    ListNode* split(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* second = slow->next;
        slow->next = nullptr;
        return second;
    }
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        // vector<int> ans;
        // ListNode* temp = head;
        // while (temp) {
        //     ans.push_back(temp->val);
        //     temp = temp->next;
        // }
        // sort(ans.begin(), ans.end());
        // int i = 0;
        // temp = head;
        // while (temp) {
        //     temp->val = ans[i++];
        //     temp = temp->next;
        // }
        // return head;
        ListNode* second = split(head);
        ListNode* left = sortList(head);
        ListNode* right = sortList(second);
        return mergeL(left, right);
    }
};