class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        int mod = 1e9 + 7;
        vector<vector<int>>dp(m + 2, vector<int>(n + 2, 0));
        dp[i + 1][j + 1] = 1;
        vector<vector<int>>tmp;
        tmp = dp;
        int ans = 0;
        for(int t = 1; t <= N; ++t){
            for(int i = 1; i <=m; ++i){
                for(int j = 1; j <= n; ++j){
                    if(tmp[i][j] != 0 ){
                        if(i == 1)
                            ans = (ans + tmp[i][j]) % mod;
                        if(i == m)
                            ans = (ans + tmp[i][j]) % mod;
                        if(j == 1)
                            ans = (ans + tmp[i][j]) % mod;
                        if(j == n)
                            ans = (ans + tmp[i][j]) % mod;
                    }
                    tmp[i][j] = ((dp[i - 1][j] + dp[i + 1][j]) % mod + (dp[i][j - 1] + dp[i][j + 1]) %mod) % mod;
                }
            }
            //cout<<t<<"   "<<ans<<endl;
            dp = tmp;
        }
        //cout<<"ans  "<<ans<<endl;
        return ans;
    }
};

/**
    1. 第一思路是搜索    
            但搜索   每一点生4点   50次   4^50  放弃
            
    2.  三层循环  50 * 50 * 50
      dp[i][j] = dp[i - 1][j] + dp[i + 1][j] + dp[i][j - 1] + dp[j + 1];
      
      而且这个  还会涉及到重复更新，弄一个副本
      优化不了
      
      错误样例   原因：sb了 ，没看到题目的mod 这一信息
      8
      50
      23(到17过，还都是正确的...)
      5
      26
*/