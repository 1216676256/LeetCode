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

1.   ����ܹ�ƥ�����  �͸���Ӧ���±긳ֵΪ1
       "()(()"   11011
       "()(())"  111111   
       Ȼ��ͳ�����1�ĸ���
*/