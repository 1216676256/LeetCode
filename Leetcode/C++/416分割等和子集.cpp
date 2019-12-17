class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int len = nums.size();
        int sum = 0;   //根据题意  可以用int  sum<= 20000
        for(int a : nums)
            sum += a;
        if(sum & 1)
            return false;
        sum = sum / 2;
        vector<int>dp(sum + 1, false);
        dp[0] = true;
        for(int i = 1; i <= len; ++i){
            for(int j = sum; j >= 0; --j){
                if(j < nums[i - 1])
                    continue;
                dp[j] = (dp[j] || dp[j - nums[i - 1]]); //优化
                if(dp[sum])
                    return true;
            }
        }
        return dp[sum];
    }
};
/**
    1.  先求出target
            然后就是兑换零钱的问题了  (而且元素是正整数)
            
            dp[i][j]   前i个 能不能组成j金额
            
            dp[i][j] = dp[i - 1][j] || d[i - 1][j - c[i]];
            优化
            dp[j] = dp[j] || dp[j - c[i]];     ++i,  j--;
*/