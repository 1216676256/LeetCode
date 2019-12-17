class Solution {
public:
    int numDecodings(string s) {
        int len = s.size();
        vector<int>dp(len + 1, 0);
        dp[0] = 1;
        dp[1] = (s[0] == '0' ? 0:1); //初始化条件
        for(int i = 2; i <= len; i++){
            int val = (s[i - 2] - '0') * 10 +s[i - 1] - '0';
            if(s[i - 1] != '0')
                dp[i] += dp[i - 1];
            if(10 <=val &&val <= 26) //两位数  条件注意一下
                dp[i] += dp[i - 2];
        }
        return dp[len];
    }
};
/**
    dp[i]  表示以第i-1为字符结尾的共有几种解码方法
      初始化 dp[0] = 1; dp[1] = 1;
      遍历 1-->n
*/