class Solution {
public:
    int ans;
    int findTargetSumWays(vector<int>& nums, int S) {
        ans = 0;
        dfs(nums, S, 0, 0);
        return ans;
    }
    
    void dfs(vector<int>& a, int target,int nsum, int ind){
        int len = a.size();
        if(ind == len){
            if(nsum == target)
                ans++;
            return ;
        }
        dfs(a, target, nsum + a[ind], ind + 1);
        dfs(a, target, nsum - a[ind], ind + 1);
    }
};


/**
   1.  暴力   2^20 = 1024 * 1024
   
   2.  动态规划
*/