class Solution {
public:
    string encode(int num) {
        int t = num + 1;
        string ans = "";
        while(t != 1){
            ans += t%2 + '0';
            t>>=1;
        }
        int len = ans.length();
        string res = "";
        for(int i = len -1; i >=0 ;i --){
            res += ans[i];
        }
        return res;
    }
};