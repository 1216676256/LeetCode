class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int leni = matrix.size();
        if(leni == 0)
            return 0;
        int lenj = matrix[0].size();
        vector<vector<int> >dp(leni + 1, vector<int>(lenj + 1, 0));
        for(int i = 1; i <= leni ;i++){
            for(int j = 1; j <= lenj; j++){
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1] + matrix[i -1][j -1] - '0';
                //cout<<dp[i][j]<<" ";
            }
           // cout<<endl;
        }
        int ans = 0;
        for(int i = 1; i <= leni; i++){
            for(int j = 1; j <= lenj; j++){
                for(int t = 1;;t++){
                    int ni = i + t -1;
                    int nj = j + t -1;
                   // cout<<ni<<"  "<<nj<<endl;
                    if(ni > leni || nj >lenj){
                        break;
                    }
                    //cout<<dp[ni][nj] - dp[ni][j - 1] - dp[i - 1][nj] + dp[i -1][j -1]<<endl;
                    if(t * t == dp[ni][nj] - dp[ni][j - 1] - dp[i - 1][nj] + dp[i -1][j -1]){
                        //cout<<"AAA"<<endl;
                        ans = max(ans, t);
                    }
                }
            }
        }
        return ans * ans;
    }
};
/**
    dp[i][j](1��ʼ)  ��ʾ(i, j)�����Ͻǵ�1�ĸ���
    ö��������  ������Ӷ�O(n^4)   ������
        ����ö��������
            ö��һ���㣬��ö�ٱ߳�  ���Ӷ�O(n^3)
    

������⣬�������Ž�   dp[i][j]  ��i��jΪ���½ǵ����������ı߳�
*/