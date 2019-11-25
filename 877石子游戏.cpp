class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>>dp(n + 2,vector<int>(n + 1, 0 ));
        for(int len = 1; len <= n; ++len){
            for(int i = 1; i <=n ; ++i){
                int j = i + len -1;
                if(j > n)   break;
                dp[i][j] = max(piles[i - 1] - dp[i +  1][j] , piles[j - 1] - dp[i][j - 1]);
            }
        }
        return dp[1][n] > 0;
    }
};
/*  而且输赢的状态和剩下的数组（无和很强烈的关系）   因为和手上的石子总数有关
    1.dfs  
        len = 500   感觉会超时（每层两个节点   共500层    ）
        
    2. 先假设dp[i][j]  为  从i到j的数组   先手拿  可以比后手多几个石头  
      长度 1 -> len 遍历
      
      
    疑问 ：  为什么要规定   长度一定是偶数呢
*/