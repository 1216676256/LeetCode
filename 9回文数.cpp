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
            ans = ans * 10 + t%10;  //����ĳ�10�����ױ�int
            t = t /10;
        }
        return ans;
    }
};
/*
   С��0  false
   >=0     ������ת�����  ��ԭ�������ǲ�����ȵ�
*/