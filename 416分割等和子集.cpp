class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int len = nums.size();
        int sum = 0;   //��������  ������int  sum<= 20000
        for(int a : nums)
            sum += a;
        if(sum & 1)
            return false;
        sum = sum / 2;
        vector<int>dp(sum + 1, false);
        dp[0] = true;
        for(int i = 1; i <= len; ++i){
            for(int j = sum; j >= 0; --j){
                if(j < nums[i - 1])
                    continue;
                dp[j] = (dp[j] || dp[j - nums[i - 1]]); //�Ż�
                if(dp[sum])
                    return true;
            }
        }
        return dp[sum];
    }
};
/**
    1.  �����target
            Ȼ����Ƕһ���Ǯ��������  (����Ԫ����������)
            
            dp[i][j]   ǰi�� �ܲ������j���
            
            dp[i][j] = dp[i - 1][j] || d[i - 1][j - c[i]];
            �Ż�
            dp[j] = dp[j] || dp[j - c[i]];     ++i,  j--;
*/