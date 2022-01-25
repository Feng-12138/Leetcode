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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* CurL1 = l1;
        ListNode* CurL2 = l2;
        ListNode* retval = new ListNode{0, CurL1};
        int counter = 0;
        ListNode* retvalF;
        ListNode *last;
        int increment = 0;
        while (CurL1 != nullptr && CurL2 != nullptr) {
            int rVal = CurL1->val + CurL2->val + increment;
            if (rVal >= 10) {
                rVal = rVal - 10;
                increment = 1;
            } else {
                increment = 0;
            }
            retval->next = new ListNode{0, CurL1};
            if (counter == 0) {
                retvalF = retval->next;
            }
            last = retval->next;
            retval = retval->next;
            retval->val = rVal;
            CurL1 = CurL1->next;
            CurL2 = CurL2->next;
            ++counter;
            continue;
        }
        if (CurL1 == nullptr && CurL2 == nullptr) {
            if (increment != 1) {
            last->next = nullptr;
            return retvalF;
        } else {
            last->next->val = 1;
            return retvalF;
        }
        }
        if (CurL1 == nullptr) {
            while (CurL2 != nullptr) {
                int rVal = CurL2->val + increment;
                if (rVal >= 10) {
                    rVal = rVal - 10;
                    increment = 1;
                } else {
                    increment = 0;
                }
                retval->next = new ListNode{rVal, CurL2};
                last = retval->next;
                retval = retval->next;
                CurL2 = CurL2->next;
            }
        } else if (CurL2 == nullptr) {
            while (CurL1 != nullptr) {
                int rVal = CurL1->val + increment;
                if (rVal >= 10) {
                    rVal = rVal - 10;
                    increment = 1;
                } else {
                    increment = 0;
                }
                retval->next = new ListNode{rVal, CurL1};
                last = retval->next;
                retval = retval->next;
                CurL1 = CurL1->next;
            }
        }
        if (increment != 1) {
            last->next = nullptr;
            return retvalF;
        } else {
            last->next->val = 1;
            return retvalF;
        }
    }
};