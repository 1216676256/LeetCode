class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if(len == 0)
            return 0;
        vector<vector<int>>dp(len, vector<int>(2,0)); 
        dp[0][0] = 0;
        dp[0][1] = nums[0];
        if(len == 1)
            return nums[0];
        dp[1][0] = dp[0][1];
        dp[1][1] = nums[1];
        for(int i = 2; i < len; i++){
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = max(dp[i - 1][0] + nums[i], max(dp[i - 2][0], dp[i -2][1] + nums[i]));
        }
        return max(dp[len - 1][0], dp[len - 1][1]);
    }
};

/** 
    看了题解 还可以优化
*/