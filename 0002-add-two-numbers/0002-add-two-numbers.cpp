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
        ListNode* head = new ListNode();
        ListNode* tmp = head; 

        int cacheNnumber = 0;
        while ((l1 != NULL) || (l2 != NULL) || cacheNnumber != 0) {
            int sum = 0;
            if (l1 != NULL) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2 != NULL) {
                sum += l2->val;
                l2 = l2->next;
            }
            sum += cacheNnumber;
            cacheNnumber = sum / 10;

            ListNode* newnode = new ListNode(sum % 10);
            tmp->next = newnode;
            tmp = tmp->next;
        }
        return head->next;
    }
};