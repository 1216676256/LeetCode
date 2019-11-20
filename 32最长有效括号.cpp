class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0;
        stack<int>t;
        int len = s.length();
        vector<int>vis(len, 0);
        for(int i = 0; i < len; i++){
            if(s[i] == '('){
                t.push(i);
            }
            else{
                if(!t.empty()){
                    int a = t.top();
                    t.pop();
                    vis[a] = 1;
                    vis[i] = 1;
                }
            }
        }
        int sum  = 0;
        for(int i = 0; i < len; i++){
            if(!vis[i])
                sum = 0;
            else{
                ans = max(ans, ++sum);
            }
        }
        return ans;
    }
};
/**
"()(()"

1.   如果能够匹配得上  就给相应的下标赋值为1
       "()(()"   11011
       "()(())"  111111   
       然后统计最多1的个数
*/