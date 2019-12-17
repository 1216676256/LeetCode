class Solution {
public:
    int reverse(int x) {
        int mx = 0x7FFFFFFF;
        int mi = 0x80000000;
        bool flag = x > 0 ? true: false;
        long long ans = 0;
        long long t = abs((long long) x);
        while(t){
            ans = ans * 10 + t%10;
            t = t/10;
        }
        if(!flag)
            ans = -ans;
        if(ans > mx || ans < mi)
            return  0;
        return (int) ans;
    }
};