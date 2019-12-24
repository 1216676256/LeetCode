class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        List<List<Integer>> ans = new ArrayList<>();
        Set<List<Integer>> res = new HashSet<>();
        int len = nums.length;
        if(len == 0)
            return ans;
        Arrays.sort(nums);
        // -1 -1 -1 4     target = 1
        for (int i = 0; i < len; ++i) {
            for (int j = i + 1; j < len; ++j) { //���ﲻ��ȥ��
                int L = j + 1;
                int R = len - 1;
                while (L < R) { // -1 -1 -1 -1 target = -1
                    //��������Ҳ����ȥ��
                    int tmp = nums[i] + nums[j] + nums[L] + nums[R];
                    if (tmp > target)
                        R--;
                    else if (tmp < target)
                        L++;
                    else {
                        res.add(Arrays.asList(nums[i], nums[j], nums[L],nums[R]));
                        L++;
                        R--;
                        
                    }
                }
            }
        }
        return new ArrayList<>(res);
    }
}

/**
 * 1.ֻ�뵽�� O��n^3) �ķ���
 * ��ȥ��������   ����ͱ���� ȥʣ�µ����������������ң�  ,�������������ظ�������
 
 �û�set����������ˣ�
 */