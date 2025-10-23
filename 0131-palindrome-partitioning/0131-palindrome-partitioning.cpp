class Solution {
public:
    vector<vector<string>> partition(string s) {
        //dfs 백포인터
        
        vector<vector<string>> answer; 
        vector<string> current;
        dfs(0, s, current, answer);
        return answer;
    }

    void dfs(int start, string &s, vector<string> &current, vector<vector<string>> &answer){
        if (start == s.size()) {
            answer.push_back(current);
            return;
        }

        for (int end = start; end < s.size(); ++end) {
            // s[start..end]가 회문인지 확인
            if (isPalindrome(s, start, end)) {
                // 부분 문자열 추가
                current.push_back(s.substr(start, end - start + 1));
                // 재귀 호출
                dfs(end + 1, s, current, answer);
                // 백트래킹 (다시 되돌리기)
                current.pop_back();
            }
        }

    }

    

    bool isPalindrome(string &s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }
};