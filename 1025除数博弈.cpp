class Solution {
public:
    bool divisorGame(int N) {
        vector<bool>dp(N + 1, false);
        dp[0] = true;
        dp[1] = false;
        for(int i= 2; i <= N; i++){
            int flag = 0;
            for(int j = 1; j< i; j++){
                if(i%j == 0){
                    dp[i] = !(dp[i - j]);
                    if(dp[i]){
                        //cout<< i <<j <<endl;
                        flag = 1;
                    }
                }
            }
            if(flag == 1)
                dp[i] = true;
        }
        return dp[N];
    }
};