class Solution {
public:
    vector<int>have;
    int len;
    int ans = 0;
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        have.resize(26,0);
        for(auto a : letters){
            have[a - 'a']++;
        }
        len = words.size();
        dfs(words,0,0,score);
        return ans;
    }
    //w  �Ѿ���õļ�ֵ
    void dfs(vector<string>& words,int ind,int w,vector<int>& score){
        if(ind == len){
            ans = max(ans,w);
            return ;
        }
        //�������
        int value = 0;
        string str = words[ind];
        int lens = str.size();
        int flag = 1;
        vector<int>remain = have;
        for(int i = 0 ;i < lens; i++){
            value+= score[str[i] - 'a'];
            if(have[str[i] - 'a'] == 0){
                flag = 0;
            }
            else
                have[str[i] - 'a']--;
        }
        if(flag == 0){
            have= remain;
        }
        else{
            dfs(words,ind + 1, w+ value,score);
            for(int i = 0 ;i < lens; i++){
                    have[str[i] - 'a']++;
            }
        }
        dfs(words,ind+ 1,w,score);
    }
};
/**  
�е��񱳰�����  
    һ��������һ���ļ�ֵ������Ϊ0����Ϊ�鲻�ˣ�   
        ҲҪ����һ������Դ����ĸ������
    ����Դһ��������£����ܻ�õ�����ֵ
    
    ���ǵ����ʵĳ����е�С  2^14 = 4096
    �ڼ��ϱ�������    4096 * 15  ���ᳬʱ 
        ��dfs
*/