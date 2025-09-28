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
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;

        // 1. 전체 길이 계산
        int length = 0;
        ListNode* cur = head;
        while (cur) {
            length++;
            cur = cur->next;
        }

        // 2. mid까지 이동 (뒤쪽 절반 시작점 찾기)
        int mid = length / 2;
        cur = head;
        for (int i = 0; i < mid; i++) {
            cur = cur->next;
        }
        if (length % 2 == 1) { 
            // 홀수면 가운데 원소 스킵
            cur = cur->next;
        }

        // 3. 뒤쪽 절반 reverse
        ListNode* prev = nullptr;
        while (cur) {
            ListNode* nextNode = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nextNode;
        }
        // 이제 prev가 뒤쪽 절반의 시작점(뒤집힌 리스트 head)

        // 4. 앞쪽 절반(head)과 뒤쪽 절반(prev) 비교
        ListNode* left = head;
        ListNode* right = prev;
        for (int i = 0; i < mid; i++) {
            if (left->val != right->val) return false;
            left = left->next;
            right = right->next;
        }

        return true;
    }
};