class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        vector<int>left(len,0);
        vector<int>right(len, 0);
        int mi = 0x7FFFFFFF;
        int cnt = 0;
        for(int i = 0; i < len; i++){
             mi = min(mi,prices[i]);
             cnt =max(cnt,prices[i] - mi);
            left[i] = cnt;
        }
        int mx = 0x80000000;
        cnt = 0;
        for(int i = len - 1; i >= 0; i--){
            mx = max(mx, prices[i]);
            cnt = max(cnt,mx - prices[i]);
            right[i] = cnt;
        }
        //for(int i = 0; i < len; i++){
       //     cout<<right[i]<<" ";
      //  }
        int res = 0;
        for(int i = 0; i < len ;i++){
            res = max(res, left[i] + ((i + 1) < len ? right[i + 1] : 0));
        }
        return res;
    }
};

/**
 1.������ֳ���������
    ÿ�����ֵ�����ͻص���  ����һ�ε�����
    O(n^2)    ͨ��199/200  ����    
    ������ͨ��ά��һ��һά���飩
    
2.

*/