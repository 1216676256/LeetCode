class Solution {
public:
    int integerBreak(int n) {
        vector<int>ans(n + 1,0);
        ans[0] = 0;
        ans[1] = 0;
        for(int i = 2; i <= n; i++){
            int res = -1;
            for(int j = 1; j <= i/2; j++){
                res = max(res, max(j,ans[j]) * max(i - j, ans[i  - j]));
            }
            ans[i] = res;
        }
        return ans[n];
    }
};

/**
   1.��ѧ����    һ�������������    Խ����һ��   ������֮�����
*/