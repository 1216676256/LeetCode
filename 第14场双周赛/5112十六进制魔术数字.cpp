class Solution {
public:
    string toHexspeak(string num) {
        long long a = 0;
        if(num.empty())
            return "ERROR";
        int n = num.length();
        for(char c : num){
            a = a*10 + c - '0';
        }
        cout<<a<<endl;
        string res = "";
        while(a){
            int mod = a % 16;
            a = a/16;
            //cout<<mod << "  "<<a<<endl;
            if(mod < 10 &&(mod != 0 && mod != 1))
               return "ERROR";
            if(mod == 0)
               res += "O";
            else if(mod == 1)
                res += "I";
            else res += ('A' + mod - 10);
            //cout<<"BBB  "<<res<<endl;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

/** 
  一开始的代码:
           string tmp;
            string mynum;
            string toHexspeak(string num) {
                if(num.empty())
                    return ERROR;
                int n = num.length();
                string res = "";
                mynum = num;
                while()

            }
            int divByx(){
                string str = mynum;
                tmp = "";
                int n = str.length();
                if(n == 0)
                    return 0;
                int a = str[0] - '0';
                int ind = 1;
                while(ind < n){
                    a = a *10 + str[ind] - '0';
                    ind++;
                    int mod = a % 16;
                    tmp += (string)(a/16);
                    a = mod;
                }
                mynum = tmp;
                return a;
            }
  1.  装化成 long  long来比较方便
*/