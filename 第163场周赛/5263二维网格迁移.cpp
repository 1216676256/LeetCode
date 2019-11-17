class Solution {
public:
    int mp[101][101];
    int leni;
    int lenj;
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        if(k == 0)
            return grid;
        leni = grid.size();
        lenj = grid[0].size();
        for(int i = 0; i< leni ;i++){
            for(int j = 0; j< lenj ;j++){
                mp[i][j] = grid[i][j];
            }
        }
        while(k--){
            tran();
        }
        for(int i = 0; i< leni ;i++){
            for(int j = 0; j< lenj ;j++){
                grid[i][j] = mp[i][j];
            }
        }
        return grid;
    }
    
    void  tran(){
        vector<int>tmp;
        int j = lenj - 1;
        for(int i= 0;i < leni;i++){
            tmp.push_back(mp[i][j]);
        }
        for(int j = lenj - 1; j >=1; j--){
            for(int i = 0; i< leni; i++){
                mp[i][j] = mp[i][j -1];
            }
        }
        for(int i = 0; i<leni;i++){
            mp[i][0] = tmp[(i + leni -1)%leni];
        }
    }
};
/**
2500*100
*/