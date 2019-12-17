class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int mx = 0x7FFFFFFF;
        vector<int>dp(amount + 1, mx);
        dp[0] = 0;
        int len = coins.size();
        for(int i = 0; i < len; ++i){
            for(int j = 0; j <= amount; j++){
                if(j - coins[i] >=0 && dp[j - coins[i]] != mx)
                    dp[j] = min(dp[j], dp[j - coins[i]] + 1);
            }
        }
        /*for(int i = 0; i <= amount; ++i){
            cout<<i<<"   "<<dp[i]<<endl;
        }
        cout<<endl;*/
        return dp[amount] == mx ? -1 : dp[amount];
    }
};

/**
   ����кö��ְ�   
   �����ղ�һ��
   
   dp[i][j]  Ϊ ǰi��Ӳ�� ��������ɽ��j����С����
   
   
   �Ż�   ��ָ�ռ併ά�ˣ�  ʱ�仹��һ����
   
   1.   ��� ֻ����һ�Σ�01������
             ���������20  �����õݹ飬��һ���ǲ��е�
             
        dp[i][j] = min(dp[i - 1][j], dp[i - 1][ j - c[i]] + 1)   //��Ӧ�úͲ��õ����
        ���Է���   i���  ֮��i  - 1���йأ�i�����ķ�ʽ�������ʿ��Լ򻯳�һά��
        
        ��� dp[j] = min(dp[j] , dp[j - c[i]] + 1)
        
        ���j   ��С�������     ��һ��j(��100)�Ľ���� j - c[i](��95) ,�й�(95�Ľ��������һ���)
        ���Ҫ�Ӵ�С���б���
        
    2.   ���������  ����ȫ����)
    
    dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1 * c[i]] + 1, dp[i-1][j - 2*c[i]] + 2,...
                    ,dp[i - 1][j - k * c[i]] + k)
    
    ����Ϊ
    dp[i][j - c[i]] =min(dp[i - 1][j -c], dp[i - 1][j - 2*c] + 1,..., dp[i - 1][j -(k -1)* c[i]] + k-1)
    
    
    �Ƴ�   dp[i][j] = min(dp[i - 1][j], dp[i][j - c[i]] + 1);
    ���Կ���   i���j �Ľ��  ֮��   i - 1 ��  ������j- c[i](����һ��Ľ��)  �й�
    
    ��Ҳ�����Ż���һά���飬  jҪ��С�������
    dp[j] = min(dp[j], dp[j - c[i]] + 1)
    
    ��ȥ���  ��ʽ��01������һ��   ֻ��j�ı�����ʽ��һ����
    3.   ÿһ����������k��
    
    
    ������01�����Ļ�����    �Ӹ�  �����ı���
    
    
*/