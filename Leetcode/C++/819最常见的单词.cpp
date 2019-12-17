class Solution {
public:
    
    string mostCommonWord(string paragraph, vector<string>& banned) {
        int len = paragraph.length();
        map<string, int>mp;
        map<string, int>mp1;
        for(string str : banned){
            mp1[str] = 1;
        }
        string tmp = "";
        int mx = 0;
        string ans = "";
        for(int i = 0 ; i < len; ++i){
            if(!judge(paragraph[i])){
                if(tmp != ""){
                    mp[tmp]++;
                    if(mp1[tmp] != 1){
                        if(mp[tmp] > mx){
                            mx = mp[tmp];
                            ans = tmp;
                        }
                    }
                }
                tmp = "";
            }
            else{
                if(paragraph[i] >= 'A' && paragraph[i] <= 'Z')
                    tmp += paragraph[i] + 'a' - 'A';
                else tmp += paragraph[i];
            }
        }
        if(tmp != "")
            mp[tmp]++;
        if(mp1[tmp] != 1 && mp[tmp] > mx){
            mx = mp[tmp];
            ans = tmp;
        }
        return ans;
    }
    bool judge(char a){
        if(a >= 'a' && a <= 'z')
            return true;
        if(a >= 'A' && a <= 'Z')
            return true;
        return false;
    }
};

/**
    1.  思路很清晰
        先把字母都转成小写的，  再提取一个个单词，  用map来记录他们的出现的次数
        map1  来记录出现在禁用名单上的单词。
*/