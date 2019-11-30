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
    1. ��һ˼·������    
            ������   ÿһ����4��   50��   4^50  ����
            
    2.  ����ѭ��  50 * 50 * 50
      dp[i][j] = dp[i - 1][j] + dp[i + 1][j] + dp[i][j - 1] + dp[j + 1];
      
      �������  �����漰���ظ����£�Ūһ������
      �Ż�����
      
      ��������   ԭ��sb�� ��û������Ŀ��mod ��һ��Ϣ
      8
      50
      23(��17������������ȷ��...)
      5
      26
*/