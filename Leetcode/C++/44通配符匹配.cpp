class Solution {
public:
    bool isMatch(string s, string p) {
        int len1 = s.length();
        int len2 = p.length();
        vector<vector<bool>>dp(len1 + 1,vector<bool>(len2 + 1,false));
        vector<bool>assit(len2 + 1,false); //��������
        dp[0][0] = true;
        assit[0] = true;
        //cout<<dp[0][0]<<" ";
        for(int i = 0; i < len2; i++){
            if(p[i] == '*')
                dp[0][i + 1] = dp[0][i];
            if(!assit[i + 1] && dp[0][i + 1])
                assit[i + 1] = true;
        }
        for(int i = 0; i < len1; ++i){
            for(int j = 0; j < len2; ++j){
                if(s[i] == p[j] || p[j] == '?'){
                    dp[i + 1][j + 1] = dp[i][j];
                    if(!assit[j + 1] && dp[i + 1][j + 1])
                        assit[j + 1] = true;
                }
                else if(p[j] == '*'){
                   /* bool flag = false;
                    for(int t = 0; t <= i+ 1; ++t){
                        if(flag)
                            break;
                        flag = dp[t][j];
                    }*/
                    //dp[i + 1][j + 1 ] = flag;
                    dp[i + 1][j + 1] = assit[j]; //����assitû�м�1
                    if(!assit[j + 1] && dp[i + 1][j + 1])
                        assit[j + 1] = true;
                }         
            }
        }
        return dp[len1][len2];
    }
};


/**
  ��ʮ����ı���
  
    nice  �Լ�д��
    
    /�о��м���ǲ�ѭ���������Ż�
    �Ľ�֮��  �������
    
    "adceb"
    "*a*b"
    
    "aa"
    "*"
    
    "ho"
    "ho**"
    
  
*/