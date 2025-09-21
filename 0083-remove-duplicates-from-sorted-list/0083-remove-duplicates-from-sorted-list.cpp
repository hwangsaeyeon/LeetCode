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
    ListNode* deleteDuplicates(ListNode* head) {
        //단일 연결리스트에서는 remove를 위해 prev 필요
        ListNode* dummy = new ListNode(-101, head);
        ListNode* cur = head; 
        ListNode* prev = dummy; 

        //prev와 cur이 같으면 remove
        while (cur != nullptr){
            if (cur->val == prev->val){
                prev->next = cur->next; 
            }
            else{
                prev = cur; 
            }
            cur = cur->next; 
        }

        ListNode* newHead = dummy->next; 
        delete dummy; 
        return newHead; 
    }


};