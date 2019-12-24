class Solution {
    private int dif = Integer.MAX_VALUE;
    int res = -1;
    public int threeSumClosest(int[] nums, int target) {
        int len = nums.length;
        Arrays.sort(nums);
        for(int i = 0; i < len; ++i){
            int L = i + 1;
            int R = len - 1;
            while(L < R){
                // ������ܻ������Ӵ
                int tmp = nums[i] + nums[L] + nums[R];
                if(tmp > target){
                    if(dif > Math.abs(target - tmp)){
                        dif = Math.abs(target - tmp);
                        res = tmp;
                    }
                    --R;
                }
                else if(tmp < target){
                    if(dif > Math.abs(target - tmp)){
                        dif = Math.abs(target - tmp);
                        res = tmp;
                    }
                    ++L;
                }
                else return target;
            }
        }
        return res;
    }
}
/**
 *   1.�о�������֮���е��� ����ȵ����⣩
 *      ���� + ˫ָ��
 */