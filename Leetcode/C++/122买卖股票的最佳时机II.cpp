class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int len = prices.size();
        for(int i = 1; i < len; i++){
            if(prices[i] >= prices[i - 1])
                ans += prices[i] - prices[i - 1];
        }
        return ans;
    }
};

/**上一次的操作

    买  卖   没操作
    
    dp[i][0]   到第i天   最后一次操作为买入
    dp[i][1]    最后一次操作为卖出
    dp[i + 1][0] = max(dp[i + 1][0], dp[i][1] -prices[i]);
    dp[i + 1][1] = max(dp[i+ 1][1], dp[i][0] + prices[1]);
      这个就变成   第i天买和卖
*/