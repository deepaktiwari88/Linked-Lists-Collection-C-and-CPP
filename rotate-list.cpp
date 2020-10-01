# Given a linked list, rotate the list to the right by k places, where k is non-negative.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* rotateRight(ListNode* head, int k) {
        if (k == 0 || !head) return head;
        ListNode* tail = head;
        int size = 1;
        while(tail->next) {
            ++size;
            tail = tail->next;
        }
        
        k %= size;
        if (!k || size == 1) return head;
        
        tail->next = head;
        k = size - k;
        while(k > 1){
            head = head->next;
            --k;
        }
        ListNode* ans = head->next;
        head->next = nullptr;
        return ans;
        