class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        long long t = 5;
        while(t <= n){
            ans += n/t;
            t = t*5;   //ע�����ﱬint
        }
        return ans;
    }
};
/**
    1.   ���Ա�֤����5�ı�����ʱ��ǰ��һ����ż��
    
    25  Ҫ������   ��� INT.max  ��ʱ��
    int ans = 0;
        int ans1 = 0;
        for(int i = 5; i <= n; i += 5){
            int t = i;
            while(t % 5 == 0){
                ans1++;
                t = t /5;
            }
           // cout<<ans1<<endl;
                
        }
        return ans1;
*/