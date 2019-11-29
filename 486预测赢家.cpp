class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        if(nums.empty())
            return false;
        int n = nums.size();
        vector<vector<int>>dp(n + 2, vector<int>(n + 2, 0));
        for(int i = 1; i <= n ; ++i){ //i  长度
            for(int j = 1; j <=n && i + j - 1 <= n; ++j){  //起始下标
                int end = i + j - 1;
                dp[j][end] = max(-dp[j + 1][end] + nums[j -1], -dp[j][end - 1] + nums[end - 1]);
               // cout<<dp[j][end]<<" ";
            }
           // cout<<endl;
        }
        return dp[1][n] >=0;
    }
};


/**
    1.  感觉好像在LeetCode写过类似的，捡石头的好像   永远是先手胜
    
    dp[i][j] 表示i到j  ，先手拿，能比后手多拿几个
    
    dp[i][j] = max(dp[i + 1][j] + nums[i], dp[i][j - 1] + nums[j]);
    
    
    i  层只和 i层、i + 1层有关   因此可以空间优化
*/