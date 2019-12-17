class Solution {
public:
    int lenx,leny;
    vector<vector<int>>dir={{0,1}, {1,0},{0,-1},{-1,0}};
    vector<vector<int>>mp;
    vector<vector<bool>>vis;
    int closedIsland(vector<vector<int>>& grid) {
        mp = grid;
        if(grid.empty())
            return 0;
        lenx = grid.size();
        leny = grid[0].size();
        int res = 0;
        vis.resize(lenx,vector<bool>(leny, false));
        for(int i =0 ;i < lenx; i++){
            for(int j = 0; j<leny ;j++){
                if(grid[i][j] == 0 &&!vis[i][j]){
                    res += bfs(i, j);
                }
            }
        }
        return res;
    }
    int bfs(int x, int y){
        int flag = 1;
        queue<point>q;
        q.push({x,y});
        while(!q.empty()){
            point now = q.front();
            q.pop();
            int nx = now.x;
            int ny = now.y;
            vis[nx][ny] = true;
            if(nx == 0 || nx == lenx - 1 || ny == 0 || ny == leny - 1){
                flag =0;
            }
            for(int i =0; i< 4; i++){
                int xx = nx + dir[i][0];
                int yy =ny + dir[i][1];
                if(0<= xx && xx < lenx && 0 <=yy && yy <leny &&!vis[xx][yy] && mp[xx][yy] == 0){
                    q.push({xx, yy});
                }
            }
        }
        return flag;
    }
    struct point{
        int x;
        int y;
    };
};
/**
    统计连通快，在加上 是否和边界想碰的条件
*/