class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>>dp(n + 2,vector<int>(n + 1, 0 ));
        for(int len = 1; len <= n; ++len){
            for(int i = 1; i <=n ; ++i){
                int j = i + len -1;
                if(j > n)   break;
                dp[i][j] = max(piles[i - 1] - dp[i +  1][j] , piles[j - 1] - dp[i][j - 1]);
            }
        }
        return dp[1][n] > 0;
    }
};
/*  ������Ӯ��״̬��ʣ�µ����飨�޺ͺ�ǿ�ҵĹ�ϵ��   ��Ϊ�����ϵ�ʯ�������й�
    1.dfs  
        len = 500   �о��ᳬʱ��ÿ�������ڵ�   ��500��    ��
        
    2. �ȼ���dp[i][j]  Ϊ  ��i��j������   ������  ���ԱȺ��ֶ༸��ʯͷ  
      ���� 1 -> len ����
      
      
    ���� ��  ΪʲôҪ�涨   ����һ����ż����
*/