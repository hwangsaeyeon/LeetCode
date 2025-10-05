class Solution {
public:
    int calculate(string s) {
        long result = 0;        // 현재까지의 계산 결과
        long num = 0;           // 현재 숫자
        int sign = 1;           // 현재 부호 (+1 또는 -1)
        stack<int> st;          // 괄호 내 상태 저장용 스택

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }
            else if (c == '+') {
                result += sign * num;
                num = 0;
                sign = 1;
            }
            else if (c == '-') {
                result += sign * num;
                num = 0;
                sign = -1;
            }
            else if (c == '(') {
                // 현재 상태를 스택에 저장
                st.push(result);
                st.push(sign);
                result = 0;
                sign = 1;
            }
            else if (c == ')') {
                result += sign * num;
                num = 0;
                result *= st.top(); st.pop(); // 괄호 앞 부호 적용
                result += st.top(); st.pop(); // 괄호 밖 결과 더하기
            }
            // 공백은 무시
        }

        result += sign * num;
        return (int)result;
    }
};
