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

/**��һ�εĲ���

    ��  ��   û����
    
    dp[i][0]   ����i��   ���һ�β���Ϊ����
    dp[i][1]    ���һ�β���Ϊ����
    dp[i + 1][0] = max(dp[i + 1][0], dp[i][1] -prices[i]);
    dp[i + 1][1] = max(dp[i+ 1][1], dp[i][0] + prices[1]);
      ����ͱ��   ��i�������
*/