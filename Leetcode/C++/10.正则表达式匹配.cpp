class Solution {
public:
    bool isMatch(string s, string p) {
        int len1 = s.length();
        int len2 = p.length();
       // if(s.empty())
         //   return p.empty();
        vector<vector<bool>>dp(len1 + 1, vector<bool>(len2 + 1, false));
        dp[0][0] = true;
        for(int i = 1; i < len2; i++){
            if(p[i] == '*')
                dp[0][i + 1] = dp[0][i- 1];
        }
        for(int i = 0; i < len1; i++){
            for(int j = 0; j < len2; j++){
                if(s[i] == p[j] || p[j] == '.')
                    dp[i + 1][j + 1] = dp[i][j];
                else if(p[j] == '*'){
                    if(p[j - 1] != s[i] && p[j - 1] != '.')
                        dp[i + 1][j + 1] = dp[i + 1][j - 1];
                    else if(p[j - 1] == s[i] || p[j - 1] == '.'){
                        dp[i + 1][j + 1] = dp[i][j + 1] || dp[i + 1][j] || dp[i + 1][j - 1];
                    }
                }
                //cout<<dp[i + 1][j + 1]<<" ";
            }
            //cout<<endl;
        }
        return dp[len1][len2];
    }
};

/**
  "ab"
  ".*"
*/