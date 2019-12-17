class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        vector<int>dp(15,0);
        dp[0] = 1;
        dp[1] = 10;
        int cnt = 9;
        for(int i = 2; i <= 10 && i <= n; i++){
            cnt = cnt * (11- i);
            dp[i] = cnt + dp[i - 1];
        }
        
        return n >=10 ? dp[10] : dp[n];
    }
};

/**
  1.有点数位dp的味道在里面
*/