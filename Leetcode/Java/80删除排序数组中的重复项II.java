class Solution {
    public int removeDuplicates(int[] nums) {
        int len = nums.length;
        if (len == 0)
            return 0;
        int pre = 0, now = 0;
        int tmp = nums[0] - 1, cnt = 0;
        // 这里的i 其实是now指针的作用
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
     *    1.  两个指针维护，  一个为 指向存储位置、  一个为  判断到的位置
     *
     *        两个变量，  一个记录当前的值，  一个记录次数
     */
}