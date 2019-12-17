class Solution {
public:
    bool isValid(string s) {
        stack<char>t;
        for(char a: s){
            if(a == ')'){
                if(t.empty())
                    return false;
                if(t.top() != '(')
                    return false;
                t.pop();
            }
            else if(a == '}'){
                if(t.empty())
                    return false;
                if(t.top() != '{')
                    return false;
                t.pop();
            }
            else if(a== ']'){
                if(t.empty())
                    return false;
                if(t.top() != '[')
                    return false;
                t.pop();
            }
            else{
                t.push(a);
            }
        }
        return t.empty();
    }
};
/**
    stack的经典应用
*/