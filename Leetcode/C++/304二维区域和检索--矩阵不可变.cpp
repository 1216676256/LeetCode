class NumMatrix {
public:
    vector<vector<int>>dp;
    int n;
    int m;
    NumMatrix(vector<vector<int>>& matrix) {
        if(matrix.empty())
            return ;
        n = matrix.size();
        m = matrix[0].size();
        dp.resize(n + 1);
        for(int i = 0; i < n + 1; ++i){
            dp[i].resize(m + 1,0);
        }
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= m; ++j){
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + matrix[i - 1][j - 1];
               // cout<<dp[i][j]<<"  ";
            } 
          //  cout<<endl;
        }
        return ;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if(row1 < 0 || col1 < 0)
            return 0;
        ++row1;
        ++col1;
        ++row2;
        ++col2;
        return dp[row2][col2] - dp[row2][col1 - 1] - dp[row1 - 1][col2] + dp[row1 - 1][col1 - 1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */