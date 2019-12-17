class Solution {
public:
    int numDecodings(string s) {
        int len = s.size();
        vector<int>dp(len + 1, 0);
        dp[0] = 1;
        dp[1] = (s[0] == '0' ? 0:1); //��ʼ������
        for(int i = 2; i <= len; i++){
            int val = (s[i - 2] - '0') * 10 +s[i - 1] - '0';
            if(s[i - 1] != '0')
                dp[i] += dp[i - 1];
            if(10 <=val &&val <= 26) //��λ��  ����ע��һ��
                dp[i] += dp[i - 2];
        }
        return dp[len];
    }
};
/**
    dp[i]  ��ʾ�Ե�i-1Ϊ�ַ���β�Ĺ��м��ֽ��뷽��
      ��ʼ�� dp[0] = 1; dp[1] = 1;
      ���� 1-->n
*/