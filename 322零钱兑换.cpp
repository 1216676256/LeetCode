class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int mx = 0x7FFFFFFF;
        vector<int>dp(amount + 1, mx);
        dp[0] = 0;
        int len = coins.size();
        for(int i = 0; i < len; ++i){
            for(int j = 0; j <= amount; j++){
                if(j - coins[i] >=0 && dp[j - coins[i]] != mx)
                    dp[j] = min(dp[j], dp[j - coins[i]] + 1);
            }
        }
        /*for(int i = 0; i <= amount; ++i){
            cout<<i<<"   "<<dp[i]<<endl;
        }
        cout<<endl;*/
        return dp[amount] == mx ? -1 : dp[amount];
    }
};

/**
   题解有好多种啊   
   可以收藏一波
   
   dp[i][j]  为 前i个硬币 ，可以组成金额j的最小次数
   
   
   优化   是指空间降维了，  时间还是一样的
   
   1.   金币 只能拿一次（01背包）
             金币数少于20  可以用递归，但一般是不行的
             
        dp[i][j] = min(dp[i - 1][j], dp[i - 1][ j - c[i]] + 1)   //对应拿和不拿的情况
        可以发现   i层的  之和i  - 1层有关，i递增的方式遍历，故可以简化成一维的
        
        变成 dp[j] = min(dp[j] , dp[j - c[i]] + 1)
        
        如果j   从小到大遍历     这一层j(如100)的结果和 j - c[i](如95) ,有关(95的结果不是上一层的)
        因此要从大到小进行遍历
        
    2.   金币无限拿  （完全背包)
    
    dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1 * c[i]] + 1, dp[i-1][j - 2*c[i]] + 2,...
                    ,dp[i - 1][j - k * c[i]] + k)
    
    又因为
    dp[i][j - c[i]] =min(dp[i - 1][j -c], dp[i - 1][j - 2*c] + 1,..., dp[i - 1][j -(k -1)* c[i]] + k-1)
    
    
    推出   dp[i][j] = min(dp[i - 1][j], dp[i][j - c[i]] + 1);
    可以看出   i层的j 的结果  之和   i - 1 层  和这层的j- c[i](即这一层的结果)  有关
    
    故也可以优化成一维数组，  j要从小到大遍历
    dp[j] = min(dp[j], dp[j - c[i]] + 1)
    
    我去结果  形式和01背包的一样   只是j的遍历方式不一样了
    3.   每一金币最多能拿k次
    
    
    就是在01背包的基础上    加个  次数的遍历
    
    
*/