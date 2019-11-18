class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        long long res = reverse(x);
        return res == (long long)x;
    }
    
    long long reverse(int t){
        long long ans = 0;
        while(t){
            ans = ans * 10 + t%10;  //这里的乘10极容易爆int
            t = t /10;
        }
        return ans;
    }
};
/*
   小于0  false
   >=0     就是求翻转后的数  和原本的数是不是相等的
*/