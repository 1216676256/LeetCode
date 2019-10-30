class Solution {
public:
    vector<int>dp;
    int numSquares(int n) {
        dp.resize(n + 1);
        dp[0] = 0;
        for(int i = 1; i <= n; i++){
            dp[i] = 0x7FFFFFFF;
            int t = sqrt(i);
            if(t * t == i){
                dp[i] = 1;
                continue;
            }
            for(int j = t; j >=1; j--){
                dp[i] = min(dp[i],dp[j * j] + dp[i - j * j]);
                //
            }
              // cout<<dp[i]<<"  "<<i<<endl;
        }
        return dp[n];
    }
};
/** 
    感觉和那个正方形的拆分有点类似
*/

/*
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25
1 2 3 1 2 3 4 2 3 4  5  3  2   3 4  1  2  3  4  2  3  4  5  3  1
                1 2  3  3  
                */