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
            for (int j = i + 1; j < len; ++j) { //这里不能去重
                int L = j + 1;
                int R = len - 1;
                while (L < R) { // -1 -1 -1 -1 target = -1
                    //所以这里也不能去重
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
 * 1.只想到了 O（n^3) 的方法
 * 先去两个数，   问题就变成了 去剩下的两个数（最左、最右）  ,但这个解决不了重复的问题
 
 用户set暴力解决好了；
 */