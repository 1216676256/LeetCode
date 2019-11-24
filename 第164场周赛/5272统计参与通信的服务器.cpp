class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int>rows(m,0);
        vector<int>cols(n, 0);
        for(int i = 0 ; i < m; i++){
            for(int j = 0; j < n; j++){
                rows[i] += grid[i][j];
                cols[j] += grid[i][j];
            }
        }
        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!grid[i][j])
                    continue;
                if(rows[i] >= 2 || cols[j] >=2)
                    ans++;
            }
        }
        return ans;
    }
};

/**
  1. �ж�ÿһ��  ��  ��һ�л�����һ��  ��û���������ϵķ�������Ԥ����һ����
*/