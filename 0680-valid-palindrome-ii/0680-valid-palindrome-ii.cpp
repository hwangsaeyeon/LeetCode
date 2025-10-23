class Solution {
public:
    bool validPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l] != s[r]) {
                // 하나 다른 경우 → 왼쪽 또는 오른쪽 문자 하나 무시하고 확인
                return isPalindrome(s, l + 1, r) || isPalindrome(s, l, r - 1);
            }
            l++;
            r--;
        }
        return true;
    }

    // 부분 문자열이 회문인지 확인하는 헬퍼 함수
    bool isPalindrome(string &s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }
};
