class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        if(len == 0)
            return false;
        int mx = nums[0];
        for(int i = 1; i <= mx && i < len; i++){
            mx = max(mx, i + nums[i]);
        }
        return mx >= len -1;
    }
};
/**
    1.��¼��0��ʼ  ������߼���mx
        �������ߵ�·���ϸ���mx
        ���mx�� len -1 ��
*/
    