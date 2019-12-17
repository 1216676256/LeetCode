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
    1.看题解的
        分治思想
        最大子序列和  情况分为三种
        1.1  在中间元素的左边
        1.2  在中间元素的右边
        1.3  中间元素在内的（遍历得到结果）
            以上三个值  做比较得到结果
*/