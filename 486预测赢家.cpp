class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        if(nums.empty())
            return false;
        int n = nums.size();
        vector<vector<int>>dp(n + 2, vector<int>(n + 2, 0));
        for(int i = 1; i <= n ; ++i){ //i  ����
            for(int j = 1; j <=n && i + j - 1 <= n; ++j){  //��ʼ�±�
                int end = i + j - 1;
                dp[j][end] = max(-dp[j + 1][end] + nums[j -1], -dp[j][end - 1] + nums[end - 1]);
               // cout<<dp[j][end]<<" ";
            }
           // cout<<endl;
        }
        return dp[1][n] >=0;
    }
};


/**
    1.  �о�������LeetCodeд�����Ƶģ���ʯͷ�ĺ���   ��Զ������ʤ
    
    dp[i][j] ��ʾi��j  �������ã��ܱȺ��ֶ��ü���
    
    dp[i][j] = max(dp[i + 1][j] + nums[i], dp[i][j - 1] + nums[j]);
    
    
    i  ��ֻ�� i�㡢i + 1���й�   ��˿��Կռ��Ż�
*/