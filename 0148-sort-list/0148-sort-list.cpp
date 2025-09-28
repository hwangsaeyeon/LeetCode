class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;


        int n = 0;
        for (ListNode* cur = head; cur; cur = cur->next) n++;

        ListNode dummy(0, head);

     
        for (int step = 1; step < n; step *= 2) {
            ListNode* prev = &dummy;
            ListNode* cur = dummy.next;

            while (cur) {
                ListNode* head1 = cur;
                int i = 1;
                for (; i < step && cur->next; i++) cur = cur->next;

                ListNode* head2 = cur->next;
                cur->next = nullptr; 
                cur = head2;


                i = 1;
                for (; i < step && cur && cur->next; i++) cur = cur->next;

                ListNode* next = nullptr;
                if (cur) {
                    next = cur->next;
                    cur->next = nullptr; 
                }


                prev->next = merge(head1, head2);


                while (prev->next) prev = prev->next;

                cur = next;
            }
        }

        return dummy.next;
    }

private:
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* cur = &dummy;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if (l1) cur->next = l1;
        if (l2) cur->next = l2;

        return dummy.next;
    }
};
