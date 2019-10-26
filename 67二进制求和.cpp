class Solution {
public:
    string addBinary(string a, string b) {
        //cout<<a<<b<<endl;
        string tmp;
        if(a.length() < b.length()){
            tmp = a;
            a = b;
            b = tmp;
        }
       // cout<<a<<endl<<b<<endl;
        int lena = a.length();
        int lenb = b.length();
        //cout<<lena <<lenb<<endl;
        int i = lena - 1;
        int j = lenb - 1;
        int flag = 0;
        while(i >= 0){
            int t = a[i] - '0' + (j < 0 ? '0' : b[j]) - '0' + flag ;
            //cout<<"AAA"<<t<<"  "<<flag<<a[i] - '0'<<"  "<<(j < 0 ? '0' : b[j]) - '0'<<j<<endl;
            flag = t/2;
            t = t%2;
            a[i] = t + '0';
            //这里还漏了情况
            i--;
            j--;
        }
        //cout<<a<<endl;
        if(flag != 0){
            return "1" + a;
        }
        else{
            return a;
        }
    }
};
/*
    1.肯定不能转化成两个十进制数相加    得到ans
        在获取ans的二进制
    2.问题类似  两个字符串相加（十进制）
        就是字符串长度   要讨论一下
*/