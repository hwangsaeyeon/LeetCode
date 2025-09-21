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
    ListNode* middleNode(ListNode* head) {
        //길이 순회
        int length = 0;
        ListNode* cur = head;
        while (cur) {
            length++;
            cur = cur->next;
        }

        int mid = length/2 ; //두개의 노드 중 뒤쪽 선택

        //mid 번째 노드까지 이동
        cur = head;
        for (int i = 0; i < mid; i++) {
            cur = cur->next;
        }
        //mid 부터 반환
        return cur;
    }
};