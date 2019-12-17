class Solution {
public:
    long long gcd(long long a, long long b){
        return b ? gcd(b, a % b) : a;
    }
    vector<int> fraction(vector<int>& cont) {
        reverse(cont.begin(), cont.end());
        int n = cont.size();
        long long a = cont[0];
        long long b = 1;
        for(int i = 1; i < n; ++i){
            long long d = gcd(b + a * cont[i], a);
            long long t = (b + a * cont[i]) /d;
            b = a / d;
            a= t;
            //cout<<a<<"  "<<b<<"  "<<d<<endl;
        }
        return {a, b};
    }
};

/** 
    1. 过程可能会爆int喲
    2.  考察gcd函数，（然而并不会也不会推导）
*/