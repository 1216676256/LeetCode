class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        leni = matrix.size();
        if(leni == 0) return ans;
        lenj = matrix[0].size();
        vector<vector<int>>dir = {{0,1},{1,0},{0,-1},{-1,0}};
        vector<vector<int>>mp;
        mp.resize(leni);
        for(int i = 0; i < leni; i++){
            mp[i].resize(lenj);
        }
        int ndir = 0;
        int nx = 0;
        int ny = -1;
        int cnt = leni * lenj;
        while(cnt){
            int xx = nx + dir[ndir][0];
            int yy = ny + dir[ndir][1];
            if(0 <= xx && xx <leni && 0 <= yy && yy< lenj && mp[xx][yy] != 1){
                nx = xx;
                ny = yy;
                ans.push_back(matrix[nx][ny]);
                mp[nx][ny] = 1;
                cnt--;
            }
            else{
                ndir = (ndir +1)%4;
            }
        }
        return ans;
    }
private:
    int leni;
    int lenj;
};