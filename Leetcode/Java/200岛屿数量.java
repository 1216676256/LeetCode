class Solution {
    private int n, m;
    private int[][] dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    public int numIslands(char[][] grid) {
        if (grid == null)
            return 0;
        n = grid.length;
        if(0 == n)
            return 0;
        m = grid[0].length;
        boolean[][] vis = new boolean[n][m];
//        boolean vis[][] = new boolean[n][m];  Çø±ð
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (vis[i][j] || grid[i][j] != '1') continue;
                vis[i][j] = true;
                ans++;
                dfs(grid, i, j, vis);
            }
        }
        return ans;
    }

    private void dfs(char[][] grid, int x, int y, boolean[][] vis) {
        for (int[] a : dir) {
            int nx = x + a[0];
            int ny = y + a[1];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || vis[nx][ny])
                continue;
            if (grid[nx][ny] != '1')
                continue;
            vis[nx][ny] = true;
            dfs(grid, nx, ny, vis);
        }
    }
}