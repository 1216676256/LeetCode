class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.empty())
            return 0;
        int len = triangle.size();
        int len1 = triangle[len - 1].size();
        vector<int>dp(len1,0);
        dp[0] = triangle[0][0];
        int mx = 0x7FFFFFFF;
       // cout<<dp[0]<<endl;
        for(int i = 1; i < len; ++i){
            int t = triangle[i].size();
            for(int j= t -1;j >= 0; --j){
                dp[j] = min(j == 0 ? mx : dp[j - 1],j == t- 1 ? mx: dp[j]) + triangle[i][j];
               // cout<<dp[j]<<" ";
            }
           // cout<<endl;
        }
        int ans = mx;
        for(int i = 0; i < len1; i++){
            ans = min(ans, dp[i]);
        }
        return ans;
    }
};

/**
     思路很简单
     就是不是很清楚   相邻的这一概念
       看了评论去的    只能往下走  或者往右下走（不能往左下走）
     1.  至顶向下  
     dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + tri[i][j]
       前提   j - 1 >=0
       
     return min(dp[len - 1][0],...,dp[len - 1][n])  
       优化    dp[j] =min(dp[j - 1], dp[j]) +tri[i][j];
       i++;
       j--;  遍历顺序很重要  反了就会错
       
       
     2. 自下向上
     
     dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]) + tri[i][j];
     return dp[0][0];
     
     因为   只和下一层有关   故可以优化成  一维
     dp[j] = min(dp[j], dp[j + 1]) + tri[i][j];
     
     i--;
     j++;
     
     int len = triangle.size();
        int len1 = triangle[len - 1].size();
        vector<int>dp(len1 + 1, 0);
        for(int i = len - 1; i >= 0; --i){
            for(int j = 0; j < len1; ++j){
                dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j];
            }
            --len1;
        }
        return dp[0];
*/

