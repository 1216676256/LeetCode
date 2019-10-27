class Solution {
public:
    bool flag = false;
    vector<int>ans;
    vector<int>res;
    vector<bool>vis;
    vector<int> circularPermutation(int n, int start) {
        vis.resize(1<<n, false);
        vis[start] = true;
        ans.push_back(start);
        dfs(n, start, 0);
        return res;
    }
    
    void dfs(int n, int start, int ind){
        if(flag)
            return ;
        if(ind == (1<<n) -1){
            res = ans;
            flag = true;
            return ;
        }
        for(int i = 0; i < n; i++){
            int cnt = ans.back() ^ (1 << i);
            //cout<<"DDD  "<<cnt<<endl;
            if(!vis[cnt]){
                //cout<<"CCC  "<<cnt<<endl;
                ans.push_back(cnt);
                vis[cnt] = true;
                dfs(n, start, ind +1);
                ans.pop_back();
                vis[cnt] = false;
            }
        }
    }
};

/**
    思路是对的   但实现的时候  细节还是不行
        比赛完之后  通过
*/