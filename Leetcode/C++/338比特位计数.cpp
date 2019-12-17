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
    1.  暴力法很简单
     用位运算的时候  要注意负数（符号位是1）
     但题目没有负数
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
        
    
    
    2.  O(n)算法  怎么搞  bitset用法？  bitcount() ???
    
    3. 看题解   f(x +b)  =f(x) + 1;  b = 2^m>x
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
    
    4.  动态规划  +  最低有效为
        f(x)  = f(x/2) + x%2;
        for(int i = 1; i <= num; i++){
            ans[i] = ans[i>>1] + (i&1);
        }
        
    5.  动态规划 + 最后设置位（右到左  第一个为1的位）
    一个数只要不为0  就要最后设置位
         x&(x - 1)的效果  
         xxx1000    x
       & xxx0111    x - 1
         xxx0000    x&(x - 1)  比x小
    
*/