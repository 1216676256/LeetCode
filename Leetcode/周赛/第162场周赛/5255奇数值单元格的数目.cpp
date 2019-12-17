class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        int ans =0;
        vector<vector<int>>mp(n,vector<int>(m,0));
        int len =indices.size();
        for(int i = 0; i <len; i++){
            int x = indices[i][0];
            int y  =indices[i][1];
            for(int j = 0; j < m; j++)
                mp[x][j]++;
            for(int j = 0; j < n; j++)
                mp[j][y]++;
        }
        for(int i  = 0; i<n; i++){
            for(int j =0; j<m ;j++){
                if(mp[i][j]%2)
                    ans++;
            }
        }
        return ans;
    }
};
/**
  Ö±½Ó±©Á¦
*/