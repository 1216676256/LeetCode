class Solution {
public:
    int minFlips(vector<vector<int>>& mat) {
        
        int m = mat.size();
        int n = mat[0].size();
        int ans = 0;
        int ind = 0;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(mat[i][j] == 1)
                    ans |= (1 << ind);
                ind++;
            }
        }
        if(ans == 0)
            return 0;
        int len = n * m;
        vector<int>dp((1 << len), -1);
        dp[0] = 0;
        queue<int>q;
        q.push(0);
        while(!q.empty()){
            int t = q.front();
            q.pop();
            int tmp;
            for(int i = 0; i < len; ++i){
                tmp = t;
                tmp ^= (1 <<i);
                if(((i + 1) % n) != 0 && n != 1){
                     tmp ^= (1 << (i + 1));
                }
                if(((i + 1) %n) != 1 && n != 1){
                    tmp ^= (1 << (i - 1));
                }
                if(i + n < len){
                    tmp ^= (1 << (i + n));
                }
                if(i - n >= 0){
                    tmp ^= (1 << (i - n));
                }
                if(dp[tmp] == -1){
                    dp[tmp] = dp[t] + 1;
                    q.push(tmp);
                }
            }
        }
        return dp[ans];
    }
};

/**
    1.  感觉变形的bfs
    
    方格就9个   状态2^9  可以bfs
     
    从0 状态开始搜索
*/