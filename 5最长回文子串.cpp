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
        int ans_t = 0;//����Ϊ-1  �Ļ� ������Ķ���ѭ����j  �����i��ʼ  ������һ�������
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
    ˼·���Ǵ��
        0-10  ��ȴ��֪��1-9��״̬
        
    ������ö�ٳ���   �Ӷ̵Ŀ�ʼ
*/