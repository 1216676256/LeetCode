class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if(len == 0)
            return 0;
        if(len == 1){
            return nums[0];
        }
        if(len == 2){
            return max(nums[0], nums[1]);
        }
        vector<int>t1,t2;
        t1 = nums;
        t2 = nums;
        t1.erase(t1.begin());
        t2.pop_back();
        t2.erase(t2.begin());
        t2.erase(t2.begin());
        return max(robII(t1), nums[0] + robII(t2));
        
    }
    int robII(vector<int>& nums) {
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
    1.  打家劫舍I的变形
        1 2 3 4 5
        1.1  1不拿   那么 2 3 4 5 就回到上一题的情况
        1.2  1拿     那么 3 4就是上一次的情况
*/