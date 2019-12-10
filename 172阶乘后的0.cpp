class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        long long t = 5;
        while(t <= n){
            ans += n/t;
            t = t*5;   //注意这里爆int
        }
        return ans;
    }
};
/**
    1.   可以保证遇到5的倍数的时候，前面一定有偶数
    
    25  要算两次   最后 INT.max  超时了
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