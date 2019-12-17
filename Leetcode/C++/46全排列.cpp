class Solution {
public:
    vector<bool>vis;
    vector<vector<int>>ans;
    vector<int>path;
    int len;
    vector<vector<int>> permute(vector<int>& nums) {
        len = nums.size();
        if(len == 0)
            return ans;
        vis.resize(len, false);
        dfs(nums, 0);
        return ans;
    }
    
    void dfs(vector<int>& vec, int ind){
        if(ind == len){
            ans.push_back(path);
        }
        for(int i = 0; i < len; i++){
            if(vis[i])
                continue;
            vis[i] = true;
            path.push_back(vec[i]);
            dfs(vec, ind + 1);
            vis[i] = false;
            path.pop_back();
        }
    }
};
/** 
    1.序列不是1->n  所以不能用vector  要用set  或者map
        或者用0->n -1  分别映射nums[0]->nums[n - 1]
*/