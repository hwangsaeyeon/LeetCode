class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size(); 
        vector<int> dp(n, 0); 
        dp[0] = cost[0]; 
        dp[1] = cost[1]; 

        //계단 i로 가는 방법은 두 가지:
        //i-1 번째 계단에서 1칸 오름
        //i-2 번째 계단에서 2칸 오름

        for (int i = 2; i < n; i++) {
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        }


        return min(dp[n-1], dp[n-2]); 
    }; 
};