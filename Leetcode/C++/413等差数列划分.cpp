class Solution {
public:
    int dp[1000 + 5];
    int numberOfArithmeticSlices(vector<int>& A) {
        init();
        if(A.empty())
            return 0;
        int n = A.size();
        int ans = 0;
        for(int i = 0; i < n - 2; ++i){
            int d = A[i + 1] - A[i];
            int cnt = 1;
            int j;
            for(j = i + 1; j < n; ++j){
                if(A[j] - A[j - 1] == d){   //   4 6 10
                    ++cnt;
                }
                else{
                    j-=2;  //这里j-2
                    break;
                }
            }
            ans += dp[cnt];
           // cout<<ans<<"   "<<cnt<<"J   "<<j<<endl;
            i = j;
        }
        return ans;
    }
    void init(){
        memset(dp, 0, sizeof(dp));
        dp[3] = 1;
        for(int i = 4; i <= 1000; ++i){
            dp[i] = dp[i - 1] + i - 2;
            //cout<<i<<"   "<<dp[i]<<endl;
        }
    }
};

/** 1 2 3 4 5  6
    1.
    类似找最长的等差数列（可重用）
    3 4 5      6
    1 3 3+2+1  4+3+2+1
    
    2 4 6 9 12 15 
    
    3 6
*/