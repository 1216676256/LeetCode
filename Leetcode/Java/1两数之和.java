class Solution {
    public static int[] twoSum(int[] nums, int target){
        Map<Integer, Integer> mp = new HashMap<Integer, Integer>();
        int len = nums.length;
        for(int i = 0; i < len; ++i){
            if(mp.containsKey(target - nums[i]) ){
                return new int[] {i, mp.get(target - nums[i])};
            }
            mp.put(nums[i], i);
        }
        return new int[]{-1,-1};
    }
}