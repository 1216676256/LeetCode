class Solution {
public:
    vector<vector<int>>edge;
    int ans;
    vector<bool>vis;
    int countArrangement(int N) {
        edge.resize(N + 1);
        vis.resize(N + 1, false);
        init(N);
        ans = 0;
        dfs(1, N);
        return ans;
    }
    void init(int n){
        for(int i = 1; i <= n; ++i){
            for(int x = 1; x <= n; ++x){
                if(x % i == 0 || i % x == 0){
                    edge[i].push_back(x);
                }
            }
        }
    }
    
    void dfs(int ind, int n){   //ind表示现在要选的是第几位
        if(ind > n){
            ans++;
            return ;
        }
        int m = edge[ind].size();
        for(int i = 0; i < m; ++i){
            int x = edge[ind][i];
            if(vis[x])  continue;
            vis[x] = true;
            dfs(ind + 1, n);
            vis[x] = false;
        }
    }
};

/**
    dfs  + 回溯
    1.  先遍历每个位能存的数(边)
        再遍历每个为就行了
*/