class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool>dp(s.size() + 1, false);
        unordered_set<string>tmp(wordDict.begin(), wordDict.end());
        dp[0] = true;
        int len = s.size();
        for(int i = 1; i <= len; i++){
            for(int j = 0; j < i ;j ++){
                if(dp[j] && tmp.find(s.substr(j, i - j)) != tmp.end()){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};
/**
    没什么思路...
        看题解  用一些库函数
*/