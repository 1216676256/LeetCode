class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        if(len == 0)
            return "";
        vector<vector<bool>>dp(1005, vector<bool>(len, false));
        for(int i = 0; i < len; i++){
            dp[i].resize(len);
            dp[i][i] = true;
        }
        int ans = 1;
        int ans_s = 0;
        int ans_t = 0;//这里为-1  的话 ，下面的二重循环的j  不会从i开始  忽略了一个的情况
        for(int i = 2; i <= len; i++){
            for(int  j = 0; j < len && i+j-1<len; j++){
                if(s[j] != s[i+j-1]){
                    dp[j][i+j-1] = false;
                    continue;
                }
                if(i == 2){
                    dp[j][i+j-1] = true;
                }
                else{
                    dp[j][i+j-1] = dp[j+1][i+j - 2];
                }
                if(dp[j][i+j-1] && i > ans){
                    ans = i;
                    ans_s = j;
                    ans_t = i+j-1;
                }
            }
        }
       // cout<<ans_s<<ans_t<<endl;
        string res = "";
        for(int i = ans_s; i <= ans_t; i++){
            res += s[i];
        }
        return res;
    }
};

/** 
    思路就是错的
        0-10  但却不知道1-9的状态
        
    但可以枚举长度   从短的开始
*/