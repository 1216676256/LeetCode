class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty()) return 0;
        long long mi = nums[0];
        long long  mx = nums[0];
        long long ans = nums[0];
        for(int i = 1; i < nums.size(); i++){
            long long t1 =  max((long long)nums[i], max(mx * nums[i],mi* nums[i]));
            long long  t2 =  min((long long)nums[i], min(mx * nums[i], mi * nums[i]));
            mx = t1 ;
            mi = t2 ;
           // cout<<mx <<" "<<mi<<endl;
            ans = max(ans,mx);
        }
        return ans;
    }
};
/**
    1.  枚举起点和终点 O(n^2)  再加上计算乘积 O(n^3)
    
    2. dp[i]  表示 第i个数选的情况的，连续的最大乘积
        dp[i + 1] = max(nums[i], dp[i] * nums[i]);
        只是直觉，不知道对不对...
        对的话，数组可以优化
        [-2,3,-4]  这个就不行了
        
        记录最大乘积和最小乘积
        中途还会爆int....
*/