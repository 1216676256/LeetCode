class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.size();
        bool flag = false;
        int ans = 0;
        int cnt = 0;
        for(int i = 0; i < len; i++){
            if(s[i] == ' '){
                if(flag)
                    ans = cnt;
                flag = false;
                cnt = 0;
                continue;
            } 
            else{
                flag = true;
                cnt++;
            }
        }
        if(s[len - 1] != ' ')
            ans = cnt;
        return ans;
    }
};