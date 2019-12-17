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
    1.记录从0开始  最多能走几步mx
        再在能走的路径上更新mx
        最后看mx与 len -1 比
*/
    