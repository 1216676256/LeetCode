class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int len1 = s1.length();
        int len2 = s2.length();
        int cnt1 = 0;
        int cnt2 = 0;
        for(int i = 0; i < len1; i++){
            if(s1[i] != s2[i]){
                if(s1[i] == 'x'){
                    cnt1++;
                }
                else{
                    cnt2++;
                }
            }
        }
        if(cnt1 % 2 + cnt2 %2 == 1)
            return -1;
        return cnt1/2 + cnt2/2 +  (cnt1 % 2 + cnt2 %2);
    }
};
/**
    1.找规律
        过一遍示例4就知道了
*/