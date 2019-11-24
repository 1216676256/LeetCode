class Solution {
public:
    int numWays(int steps, int arrLen) {
        vector<int>dp(arrLen + 1, 0);
        vector<int>tmp(arrLen + 1, 0);
        dp[1] = 1;
        tmp[1] = 1;
        int mod = 1e9+7;
        for(int i = 1; i <= steps; ++i){
            for(int j = 1; j <= i + 1 && j <= arrLen; j++){
                if(j == 1){
                    tmp[j] = (dp[j] + dp[j + 1])%mod;
                }
                else if(j != arrLen){
                    tmp[j] = ((dp[j -1] + dp[j])%mod + dp[j + 1])%mod;
                }
                else if(j == arrLen){
                    tmp[j] = (dp[j] + dp[j - 1])%mod;
                }
            }
            dp = tmp;
        }
        return dp[1];
    }
};
/**
    来一发暴力 
        500*500
*/