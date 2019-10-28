class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int len = cost.size();
        vector<int>dp(len, 0);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i = 2; i < len; i++){
            dp[i] = min(dp[i - 1] + cost[i], dp[i - 2] + cost[i]);
        }
        return min(dp[len - 2], dp[len - 1]);
    }
};

/**
    题解
        你可以把最后一层阶梯看做是目的地，即不需要耗费体力值
    
    
    是要爬上楼顶
*/