class Solution {
    public int removeDuplicates(int[] nums) {
        int len = nums.length;
        if (len == 0)
            return 0;
        int pre = 0, now = 0;
        int tmp = nums[0] - 1, cnt = 0;
        // �����i ��ʵ��nowָ�������
        for (int i = 0; i < len; ++i) {
            if (nums[i] == tmp) {
                cnt++;
                if (cnt <= 2) {
                    nums[pre++] = nums[i];
                }
            } else {
                cnt = 1;
                tmp = nums[i];
                nums[pre++] = nums[i];
            }
        }
        return pre;
    }
    /**
     *    1.  ����ָ��ά����  һ��Ϊ ָ��洢λ�á�  һ��Ϊ  �жϵ���λ��
     *
     *        ����������  һ����¼��ǰ��ֵ��  һ����¼����
     */
}