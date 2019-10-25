class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int inf = 0x80000000;
        int res = inf;
        int sum = 0;
        int len = nums.size();
        for(int i  = 0; i < len; i++){
            sum += nums[i];
            res = max(sum, res);
            if(sum < 0)
                sum = 0;
        }
        return res;
    }
};



/**
    1.������
        ����˼��
        ��������к�  �����Ϊ����
        1.1  ���м�Ԫ�ص����
        1.2  ���м�Ԫ�ص��ұ�
        1.3  �м�Ԫ�����ڵģ������õ������
            ��������ֵ  ���Ƚϵõ����
*/