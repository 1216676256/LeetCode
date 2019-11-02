class Solution {
public:
    vector<bool>vis;
    set<vector<int>>ans;
    vector<int>path;
    int len;
    vector<vector<int>>res;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        len = nums.size();
        if(len == 0)
            return res;
        vis.resize(len, false);
        dfs(nums, 0);
        for(vector<int>s : ans){
            res.push_back(s);
        }
        return res;
    }
    
    void dfs(vector<int>& vec, int ind){
        if(ind == len){
            ans.insert(path);
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