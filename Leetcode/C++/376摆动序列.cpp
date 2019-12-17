class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int n = nums.size();
        int mx = 1;
        vector<vector<int>>dp(n, vector<int>(2,1));
        for(int i = 1; i < n; ++i){
            for(int j = 0; j < i; ++j){
                if(nums[i] == nums[j])
                    continue;
                else if(nums[i] > nums[j]){
                    dp[i][0] = max(dp[i][0], dp[j][1] + 1);
                    mx = max(mx, dp[i][0]);
                }
                else{
                    dp[i][1] = max(dp[i][1], dp[j][0] + 1);
                    mx = max(mx, dp[i][1]);
                }
            }
        }
        return mx;
    }
};

/**  ��368  ��������Ӽ��е���

     dp[i][0]  �Ե�i��Ԫ��Ϊĩβ��    ����ֵΪ����  �����е������
     dp[i][1]                        ����ֵΪ����  �����е�....
           ��ʼ��  dp[i][0]  dp[i][1] = 1;
           �����ض�������
           dp[i][0] = max(dp[i][0], dp[j][1] + 1) 
           dp[i][1] = max(dp[i][1], dp[j][0] + 1)    j<i;
    
    ��������:
    [126,37,130,225,239,77,235,333,30,69,294,128,163,17,224,229,128,59,205,265,328,259,337,93,354,316,309,67,36,88,133,359,8,335,247,209,279,94,41,62]
    
  myoutput: 24
  answer: 25
  dp[i][1] = max(dp[i][1], dp[j][0] + 1);   i���1��...
*/