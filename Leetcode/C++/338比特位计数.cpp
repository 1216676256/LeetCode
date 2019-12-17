class Solution {
public:
    vector<int> countBits(int num) {
        vector<int>ans(num + 1, 0);
        for(int i = 1; i <= num; ++i){
            ans[i] = ans[i&(i - 1)] + 1;
        }
        return ans;
    }
};
/**
    1.  �������ܼ�
     ��λ�����ʱ��  Ҫע�⸺��������λ��1��
     ����Ŀû�и���
             vector<int>res;
        for(int i = 0; i <= num; i++){
            res.push_back(cnt(i));
        }
        return res;
    }
    
    int cnt(int n){
        int ans = 0;
        while(n){
            if(n&1)  ans++;
            n>>=1;
        }
        return ans;
        
    
    
    2.  O(n)�㷨  ��ô��  bitset�÷���  bitcount() ???
    
    3. �����   f(x +b)  =f(x) + 1;  b = 2^m>x
        vector<int>ans(num + 1, 0);
            int i = 0;
            int b = 1;
            while(b <=num){
                while(i < b && i + b <=num){
                    ans[i + b] = ans[i] + 1;
                    i++;
                }
                i = 0;
                b<<=1;
            }
            return ans;
    
    4.  ��̬�滮  +  �����ЧΪ
        f(x)  = f(x/2) + x%2;
        for(int i = 1; i <= num; i++){
            ans[i] = ans[i>>1] + (i&1);
        }
        
    5.  ��̬�滮 + �������λ���ҵ���  ��һ��Ϊ1��λ��
    һ����ֻҪ��Ϊ0  ��Ҫ�������λ
         x&(x - 1)��Ч��  
         xxx1000    x
       & xxx0111    x - 1
         xxx0000    x&(x - 1)  ��xС
    
*/