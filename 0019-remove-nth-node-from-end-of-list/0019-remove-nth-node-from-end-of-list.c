/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* m_head1 = head;
    int maxNode = 0;
    while (m_head1 != NULL) {
        maxNode++;
        m_head1 = m_head1->next;
    }

    if (n > maxNode || n <= 0) {
        return NULL;
    }

    int needDel = maxNode - n; // 1 - 1
    if (needDel == 0) {
        return head->next;
    }

    m_head1 = head;
    while (needDel != 1) {
        m_head1 = m_head1->next;
        needDel--;
    }
    m_head1->next = m_head1->next->next;
    return head;
}