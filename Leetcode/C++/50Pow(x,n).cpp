class Solution {
public:
    double myPow(double x, int n) {
        if(x == 0 || x == 1){
            return x;
        }
        int flag = n>= 0 ? 0 :1;
        long long t = (long long)abs((long long)n);
        double ans = 1;
        while(t){
            if(t&1){
                ans*=x;
            }
            x= x*x;
            t>>=1;
        }
        if(flag)
            ans = 1.0/ans;
        return ans;
    }
};
/*
  x  = 0 ,1  ,其他、数
  n  为 正数和负数
  
  n = abs(n) 会爆int
*/